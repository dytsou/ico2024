module alu#(parameter DWIDTH = 32)
(
    input  [3 : 0]        op,   // Operation to perform.
    input  [DWIDTH-1 : 0] rs1,  // Input data #1.
    input  [DWIDTH-1 : 0] rs2,  // Input data #2.
    output [DWIDTH-1 : 0] rd,   // Result of computation.
    output zero,                // zero = 1 if rdis 0, 0 otherwise.
    output overflow             // overflow = 1 if overflow happens.
);

assign rd = (op == 4'b0000) ? rs1 & rs2 :
            (op == 4'b0001) ? rs1 | rs2 :
            (op == 4'b0010) ? rs1 + rs2 :
            (op == 4'b0110) ? rs1 - rs2 :
            (op == 4'b1100) ? ~(rs1 | rs2) :
            (op == 4'b0111) ? ($signed(rs1) < $signed(rs2)) ? 32'h1 : 32'h0 :
            32'h0;
assign zero = (rd == 0);
assign overflow = (op == 4'b0010) ? ((rs1[31] & rs2[31] & ~rd[31]) | (~rs1[31] & ~rs2[31] & rd[31])) : 
                  (op == 4'b0110) ? ((rs1[31] & ~rs2[31] & ~rd[31]) | (~rs1[31] & rs2[31] & rd[31])) :
                    1'b0;

endmodule
