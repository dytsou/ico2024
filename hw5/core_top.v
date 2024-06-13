module core_top #(
    parameter DWIDTH = 32
)(
    input                 clk,
    input                 rst
);
    // Imem 
    wire [31 : 0] addr;

    // Decode
    wire [DWIDTH-1:0] instr;
    wire [2 : 0]      jump_type;
    wire [DWIDTH-1:0] jump_addr;
    wire              we_regfile;
    wire              we_dmem;
    wire [3 : 0]      op;
    wire              ssel; 
    wire [DWIDTH-1:0] imm;
    wire [4 : 0]      rs1_id;
    wire [4 : 0]      rs2_id;
    wire [4 : 0]      rdst_id;
    wire  [DWIDTH-1:0] rdst;
    wire [2 : 0]      branch;
    wire [5 : 0]      rdst_ctrl;

    // wirefile
    wire [DWIDTH-1:0] rs1;
    wire [DWIDTH-1:0] rs2;
    
    // Dmem
    wire [DWIDTH-1:0] rdata_dmem;

    // Alu
    // rs1_ALU == rs1_forward
    wire  [DWIDTH-1:0] rs2_ALU;
    wire              zero;
    wire              overflow;
    wire [DWIDTH-1:0] rd;    

    // Jump type
    localparam [2:0] J_TYPE_NOP = 3'b000,
                     J_TYPE_BEQ = 3'b001,
                     J_TYPE_JAL = 3'b010,
                     J_TYPE_JR  = 3'b011,
                     J_TYPE_J   = 3'b100;

    // Program Counter signals
    reg  [DWIDTH-1:0] pc;

    // Hazard control signals
    // ID stage
    wire [DWIDTH-1:0] ID_pc;
    wire [DWIDTH-1:0] ID_instr;
    wire              stall;

    // EX stage
    wire [DWIDTH-1:0] EX_pc;
    wire [DWIDTH-1:0] EX_jump_addr;
    wire [2 : 0]      EX_jump_type;
    wire [2 : 0]      EX_branch;
    wire              EX_stall;
    wire              EX_we_dmem;
    wire              EX_we_regfile;
    wire [3 : 0]      EX_op;
    wire  [DWIDTH-1:0] EX_imm;
    wire [DWIDTH-1:0] EX_rs1;
    wire [DWIDTH-1:0] EX_rs2;
    wire [4 : 0]      EX_rs1_id;
    wire [4 : 0]      EX_rs2_id;
    wire              EX_ssel;
    wire [4 : 0]      EX_rdst_id;
    wire [5 : 0]      EX_rdst_ctrl;
    
    // MEM stage
    wire [DWIDTH-1:0] MEM_pc;
    wire [2 : 0]      MEM_jump_type;
    wire [2 : 0]      MEM_branch;
    wire [DWIDTH-1:0] MEM_imm;
    wire              MEM_zero;
    wire              MEM_stall;
    wire              MEM_we_dmem;
    wire              MEM_we_regfile;
    wire [4 : 0]      MEM_rdst_id;
    wire [DWIDTH-1:0] MEM_rd;
    wire [DWIDTH-1:0] MEM_rs2;
    wire [5 : 0]      MEM_rdst_ctrl;

    // WB stage
    wire [DWIDTH-1:0] WB_pc;
    wire [4 : 0]      WB_rdst_id;
    wire [DWIDTH-1:0] WB_rd;
    wire              WB_we_regfile;
    wire [DWIDTH-1:0] WB_rdata_dmem;
    wire [5 : 0]      WB_rdst_ctrl;

    // Hazard control signals
    wire pc_write;
    wire IF_ID_write;
    wire IF_ID_flush;
    wire ID_EX_flush;
    wire EX_MEM_flush;

    wire [DWIDTH-1:0] rs1_forward;
    wire [DWIDTH-1:0] rs2_forward;

    assign rdst = (WB_rdst_ctrl == 6'b100011) ? WB_rdata_dmem : (WB_rdst_ctrl == 6'b000011) ? WB_pc+4 : WB_rd;
    assign rs2_ALU = (EX_ssel == 0) ? EX_imm : rs2_forward;

    imem imem_inst(
        .addr(pc[5:0]),
        .rdata(instr)
    );

    cpu_pipeline #(.DWIDTH(64)) ifid(
        // input
        .clk(clk), 
        .rst(rst), 
        .flush(IF_ID_flush),
        .write(IF_ID_write),
        .data_i({pc, instr}), // 64-bit
        // output
        .data_o({ID_pc, ID_instr})
    );

    decode decode_inst (
        // input
        .instr(ID_instr),

        // output  
        .jump_type(jump_type),
        .jump_addr(jump_addr),
        .we_regfile(we_regfile),
        .we_dmem(we_dmem),

        .op(op),
        .ssel(ssel),
        .imm(imm),
        .rs1_id(rs1_id),
        .rs2_id(rs2_id),
        .rdst_id(rdst_id),
        .branch(branch),
        .rdst_ctrl(rdst_ctrl)
    );

    load_use_hazard load_use_hazard_inst (
        // input
        .clk(clk),
        .rst(rst),
        .instr(ID_instr[31:26]),
        // output
        .stall(stall)
    );

    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(WB_we_regfile),
        .rdst_id(WB_rdst_id),
        .rdst(rdst),


        // output 
        .rs1(rs1), // rs
        .rs2(rs2)  // rt
    );

    cpu_pipeline #(.DWIDTH(195)) idex(
        // input
        .clk(clk),
        .rst(rst),
        .flush(ID_EX_flush),
        .write(1),
        .data_i({
            ID_pc, // 32
            jump_addr, // 32
            jump_type, // 3
            branch, // 3
            stall, // 1
            we_dmem, // 1
            we_regfile, // 1
            op, // 4
            imm, // 32
            ssel, // 1
            rs1, // 32
            rs2, // 32
            rs1_id, // 5
            rs2_id, // 5
            rdst_id, // 5
            rdst_ctrl}), // 6
        // output
        .data_o({
            EX_pc, // 32
            EX_jump_addr, // 32
            EX_jump_type, // 3
            EX_branch, // 3
            EX_stall, // 1
            EX_we_dmem, // 1
            EX_we_regfile, // 1
            EX_op, // 4
            EX_imm, // 32
            EX_ssel, // 1
            EX_rs1, // 32
            EX_rs2, // 32
            EX_rs1_id, // 5
            EX_rs2_id, // 5
            EX_rdst_id, // 5
            EX_rdst_ctrl}) // 6
    );

    alu alu_inst (
        // input
        .op(EX_op),
        .rs1(rs1_forward), 
        .rs2(rs2_ALU),

        // output
        .rd(rd),
        .zero(zero),
        .overflow(overflow)
    );

    cpu_pipeline #(.DWIDTH(149)) exmem(
        // input
        .clk(clk),
        .rst(rst),
        .flush(EX_MEM_flush),
        .write(1),
        .data_i({
            EX_pc, // 32
            EX_branch, // 3
            EX_jump_type, // 3
            EX_imm, // 32
            EX_stall, // 1
            EX_we_dmem, // 1
            EX_we_regfile, // 1
            EX_rdst_id, // 6 
            rd, // 32
            zero, // 1 
            rs2_forward, // 32 
            EX_rdst_ctrl}), // 6 
        // output
        .data_o({
            MEM_pc, // 32
            MEM_branch, // 3
            MEM_jump_type, // 3
            MEM_imm, // 32
            MEM_stall, // 1
            MEM_we_dmem, // 1
            MEM_we_regfile, // 1
            MEM_rdst_id, // 6
            MEM_rd, // 32
            MEM_zero, // 1
            MEM_rs2, // 32
            MEM_rdst_ctrl}) // 6
    );

    // Dmem
    dmem dmem_inst (
        .clk(clk),
        .addr(MEM_rd),
        .we(MEM_we_dmem),
        .wdata(MEM_rs2),
        // output
        .rdata(rdata_dmem)
    );

    cpu_pipeline #(.DWIDTH(108)) memwb(
        // input
        .clk(clk),
        .rst(rst),
        .flush(0),
        .write(1),
        .data_i({
            MEM_pc, // 32
            MEM_rdst_id, // 5
            MEM_rd, // 32
            MEM_we_regfile, // 1
            rdata_dmem, // 32
            MEM_rdst_ctrl}), // 6
        // output
        .data_o({
            WB_pc, // 32
            WB_rdst_id, // 5
            WB_rd, // 32
            WB_we_regfile, // 1
            WB_rdata_dmem, // 32
            WB_rdst_ctrl}) // 6
    );

    

    // Hazard control
    hazard_ctrl hazard_ctrl_inst (
        // input
        .branch(MEM_branch),
        .memory_read({EX_stall, stall}),
        .EX_rdst_id(EX_rdst_id),
        .ID_rs_id(rs1_id),
        .ID_rt_id(rs2_id),
        // output
        .pc_write(pc_write),
        .IF_ID_write(IF_ID_write),
        .IF_ID_flush(IF_ID_flush),
        .ID_EX_flush(ID_EX_flush),
        .EX_MEM_flush(EX_MEM_flush)
    );

    // Forward unit
    forward_unit forward_unit_instA (
        // input
        .clk(clk),
        .MEM_we_regfile(MEM_we_regfile),
        .WB_we_regfile(WB_we_regfile),
        .EX_rs_id(EX_rs1_id),
        .MEM_rdst_id(MEM_rdst_id),
        .WB_rdst_id(WB_rdst_id),
        .MEM_rd(MEM_rd),
        .rdst(rdst),
        .rs(EX_rs1),
        // output
        .rs_forward(rs1_forward)
    );
    forward_unit forward_unit_instB (
        // input
        .clk(clk),
        .MEM_we_regfile(MEM_we_regfile),
        .WB_we_regfile(WB_we_regfile),
        .EX_rs_id(EX_rs2_id),
        .MEM_rdst_id(MEM_rdst_id),
        .WB_rdst_id(WB_rdst_id),
        .MEM_rd(MEM_rd),
        .rdst(rdst),
        .rs(EX_rs2),
        // output
        .rs_forward(rs2_forward)
    );

    // Program Counter
    always @(negedge clk) begin
        if (rst) begin
            pc <= 0;
        end
        else begin
            if (pc_write) begin
                if (MEM_jump_type == J_TYPE_NOP)
                    pc <= pc + 4;
                else if (MEM_jump_type == J_TYPE_BEQ && MEM_zero)
                    pc <= pc + 4 + 4 * imm;
                else if (MEM_jump_type == J_TYPE_JAL)
                    pc <= jump_addr[27:0] + (pc[31:28] << 28);
                else if (MEM_jump_type == J_TYPE_JR)
                    pc <= rs1;
                else if (MEM_jump_type == J_TYPE_J)
                    pc <= jump_addr[27:0] + (pc[31:28] << 28);
                else 
                    pc <= pc + 4;  
            end
            else begin
                pc <= pc;
            end
        end 
    end
endmodule

module cpu_pipeline #(
    parameter DWIDTH = 0
)(
    input                 clk,
    input                 rst,
    input                 flush,
    input                 write,
    input  [DWIDTH-1 : 0] data_i,
    output reg [DWIDTH-1 : 0] data_o
);
    always @(posedge clk) begin
        data_o <= (flush || rst) ? 0 : write ? data_i :  data_o;    
    end
endmodule


module forward_unit #(
    parameter DWIDTH = 32
)(
    input                 clk,
    input                 MEM_we_regfile,
    input                 WB_we_regfile,
  
    input [5 : 0]         EX_rs_id,
    input [5 : 0]         MEM_rdst_id,
    input [5 : 0]         WB_rdst_id,
    input [DWIDTH-1:0]    MEM_rd,
    input [DWIDTH-1:0]    rdst,
    input [DWIDTH-1:0]    rs,
    output reg [DWIDTH-1:0]    rs_forward
);
    always @(negedge clk) begin
        if(EX_rs_id == MEM_rdst_id && MEM_rdst_id != 0 && MEM_we_regfile) begin
            rs_forward <= MEM_rd;
        end
        else if(EX_rs_id == WB_rdst_id && WB_rdst_id != 0 && WB_we_regfile)
            rs_forward <= rdst;
        else
            rs_forward <= rs;
    end
endmodule

module load_use_hazard (
    input                 clk,
    input                 rst,
    input[5 : 0]          instr,
    output reg            stall
);

    always @(posedge clk) begin
        if(rst) begin
            stall <= 0;
        end
        else begin
            if(instr == 6'b100011)
                stall <= 1;
            else
                stall <= 0;
        end
    end
endmodule

