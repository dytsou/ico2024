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
    

    // Regfile
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

    always @(posedge clk) begin
        if (rst)
            pc <= 0;
        else if (jump_type == J_TYPE_NOP)
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

    assign rs2_ALU = (ssel == 0) ? imm : rs2;
    assign rdst = (instr[31:26] == 6'b100011) ? rdata_dmem : (instr[31:26] == 6'b000011) ? pc+4 : rd;

    imem imem_inst(
        .addr(pc[5:0]),
        .rdata(instr)
    );

    decode decode_inst (
        // input
        .instr(instr),

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
        .rdst_id(rdst_id)
    );

    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(we_regfile),
        .rdst_id(rdst_id),
        .rdst(rdst),

        // output 
        .rs1(rs1), // rs
        .rs2(rs2)  // rt
    );

    alu alu_inst (
        // input
        .op(op),
        .rs1(rs1),
        .rs2(rs2_ALU),

        // output
        .rd(rd),
        .zero(zero),
        .overflow(overflow)
    );

    // Dmem
    dmem dmem_inst (
        .clk(clk),
        .addr(rd[5:0]),
        .we(we_dmem),
        .wdata(rs2),
        .rdata(rdata_dmem)
    );

endmodule