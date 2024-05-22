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
    // IF_ID
    wire [DWIDTH-1:0] IF_ID_pc;
    wire [DWIDTH-1:0] IF_ID_instr;
    // ID_EX
    wire [DWIDTH-1:0] ID_EX_pc;
    wire [DWIDTH-1:0] ID_EX_jump_addr;
    wire [2 : 0]      ID_EX_branch;
    wire              ID_EX_we_dmem;
    wire              ID_EX_we_regfile;
    wire [3 : 0]      ID_EX_op;
    wire [DWIDTH-1:0] ID_EX_imm;
    wire [DWIDTH-1:0] ID_EX_rs1;
    wire [DWIDTH-1:0] ID_EX_rs2;
    wire              ID_EX_ssel;
    wire [4 : 0]      ID_EX_rdst_id;
    wire [5 : 0]      ID_EX_rdst_ctrl;
    
    // EX_MEM
    wire [DWIDTH-1:0] EX_MEM_pc;
    wire [2 : 0]      EX_MEM_branch;
    wire              EX_MEM_we_dmem;
    wire              EX_MEM_we_regfile;
    wire [4 : 0]      EX_MEM_rdst_id;
    wire [DWIDTH-1:0] EX_MEM_rd;
    wire [DWIDTH-1:0] EX_MEM_rs2;
    wire [5 : 0]      EX_MEM_rdst_ctrl;

    // MEM_WB
    wire [DWIDTH-1:0] MEM_WB_pc;
    wire [4 : 0]      MEM_WB_rdst_id;
    wire [DWIDTH-1:0] MEM_WB_rd;
    wire              MEM_WB_we_regfile;
    wire [DWIDTH-1:0] MEM_WB_rdata_dmem;
    wire [5 : 0]      MEM_WB_rdst_ctrl;

    // Hazard control signalswe
    wire pc_write;
    wire IF_ID_write;
    wire IF_ID_flush;
    wire ID_EX_flush;
    wire EX_MEM_flush;
    wire stall;

    // memory read
    reg memory_read;
    assign memory_read = ID_EX_we_regfile || ID_EX_we_dmem;

    assign rdst = (MEM_WB_rdst_ctrl == 6'b100011) ? MEM_WB_rdata_dmem : (MEM_WB_rdst_ctrl == 6'b000011) ? MEM_WB_pc+4 : MEM_WB_rd;
    assign rs2_ALU = (ID_EX_ssel == 0) ? ID_EX_imm : ID_EX_rs2;

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
        .data_o({IF_ID_pc, IF_ID_instr})
    );

    decode decode_inst (
        // input
        .instr(IF_ID_instr),

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

    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(MEM_WB_we_regfile),
        .rdst_id(MEM_WB_rdst_id),
        .rdst(rdst),


        // output 
        .rs1(rs1), // rs
        .rs2(rs2)  // rt
    );

    cpu_pipeline #(.DWIDTH(181)) idex(
        // input
        .clk(clk),
        .rst(rst),
        .flush(ID_EX_flush),
        .write(1),
        .data_i({
            IF_ID_pc, // 32
            jump_addr, // 32
            branch, // 3
            we_dmem, // 1
            we_regfile, // 1
            op, // 4
            imm, // 32
            ssel, // 1
            rs1, // 32
            rs2, // 32
            rdst_id, // 5
            rdst_ctrl}), // 6
        // output
        .data_o({
            ID_EX_pc, // 32
            ID_EX_jump_addr, // 32
            ID_EX_branch, // 3
            ID_EX_we_dmem, // 1
            ID_EX_we_regfile, // 1
            ID_EX_op, // 4
            ID_EX_imm, // 32
            ID_EX_ssel, // 1
            ID_EX_rs1, // 32
            ID_EX_rs2, // 32
            ID_EX_rdst_id, // 5
            ID_EX_rdst_ctrl}) // 6
    );

    alu alu_inst (
        // input
        .op(ID_EX_op),
        .rs1(ID_EX_rs1),
        .rs2(rs2_ALU),

        // output
        .rd(rd),
        .zero(zero),
        .overflow(overflow)
    );

    cpu_pipeline #(.DWIDTH(112)) exmem(
        // input
        .clk(clk),
        .rst(rst),
        .flush(EX_MEM_flush),
        .write(1),
        .data_i({
            ID_EX_pc, // 32
            ID_EX_branch, // 3
            ID_EX_we_dmem, // 1
            ID_EX_we_regfile, // 1
            ID_EX_rdst_id, // 5
            rd, // 32
            ID_EX_rs2, // 32
            ID_EX_rdst_ctrl}), // 6
        // output
        .data_o({
            EX_MEM_pc, // 32
            EX_MEM_branch, // 3
            EX_MEM_we_dmem, // 1
            EX_MEM_we_regfile, // 1
            EX_MEM_rdst_id, // 5
            EX_MEM_rd, // 32
            EX_MEM_rs2, // 32
            EX_MEM_rdst_ctrl}) // 6
    );

    // Dmem
    dmem dmem_inst (
        .clk(clk),
        .addr(EX_MEM_rd),
        .we(EX_MEM_we_dmem),
        .wdata(EX_MEM_rs2),
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
            EX_MEM_pc, // 32
            EX_MEM_rdst_id, // 5
            EX_MEM_rd, // 32
            EX_MEM_we_regfile, // 1
            rdata_dmem, // 32
            EX_MEM_rdst_ctrl}), // 6
        // output
        .data_o({
            MEM_WB_pc, // 32
            MEM_WB_rdst_id, // 5
            MEM_WB_rd, // 32
            MEM_WB_we_regfile, // 1
            MEM_WB_rdata_dmem, // 32
            MEM_WB_rdst_ctrl}) // 6
    );

    // Hazard control
    hazard_ctrl hazard_ctrl_inst (
        // input
        .branch(EX_MEM_branch),
        .memory_read(memory_read),
        .ID_EX_rdst_id(ID_EX_rdst_id),
        .IF_ID_rs_id(rs1_id),
        .IF_ID_rt_id(rs2_id),
        .stall_i(stall),

        // output
        .pc_write(pc_write),
        .IF_ID_write(IF_ID_write),
        .IF_ID_flush(IF_ID_flush),
        .ID_EX_flush(ID_EX_flush),
        .EX_MEM_flush(EX_MEM_flush),
        .stall_o(stall)
    );


    // Program Counter
    always @(negedge clk) begin
        if (rst) begin
            pc <= 0;
        end
        else begin
            if (pc_write) begin
                if (jump_type == J_TYPE_NOP)
                    pc <= pc + 4;
                else if (jump_type == J_TYPE_BEQ && zero)
                    pc <= pc + 4 + 4 * imm;
                else if (jump_type == J_TYPE_JAL)
                    pc <= jump_addr[27:0] + (pc[31:28] << 28);
                else if (jump_type == J_TYPE_JR)
                    pc <= rs1;
                else if (jump_type == J_TYPE_J)
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
    always @(negedge clk) begin
        data_o <= (flush || rst) ? 0 : write ? data_i :  data_o;    
    end
endmodule