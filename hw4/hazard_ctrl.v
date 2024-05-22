module hazard_ctrl #(parameter DWIDTH = 32)
    (
        input [2:0]        branch,      // branch signal
        input              memory_read, // memory read signal
        input [4:0]        ID_EX_rdst_id,    // ID_EX.rt
        input [4:0]        IF_ID_rs_id,    // IF_ID.rs
        input [4:0]        IF_ID_rt_id,    // IF_ID.rt
        input              stall_i,

        output reg         pc_write,    // PC write signal
        output reg         IF_ID_write,   // register file write signal
        output reg         IF_ID_flush,    
        output reg         ID_EX_flush,    
        output reg         EX_MEM_flush,
        output reg         stall_o
    );

    always @(*) begin
        if(branch != 3'b000) begin // branch hazard
            pc_write = 1'b1;
            IF_ID_write = 1'b1;
            IF_ID_flush = 1'b1;
            ID_EX_flush = 1'b1;
            EX_MEM_flush= 1'b1;
            stall_o = 1'b0;
            $display("branch hazard");
        end
        else begin
            if (stall_i) begin //
                pc_write = 1'b0;
                IF_ID_write = 1'b0;
                IF_ID_flush = 1'b0;
                ID_EX_flush = 1'b1;
                EX_MEM_flush= 1'b0;
                stall_o = 1'b0;
            end
            else if(memory_read && (ID_EX_rdst_id == IF_ID_rs_id || ID_EX_rdst_id == IF_ID_rt_id)) begin // load-use hazard
                pc_write = 1'b0;
                IF_ID_write = 1'b0;
                IF_ID_flush = 1'b0;
                ID_EX_flush = 1'b1;
                EX_MEM_flush= 1'b0;
                stall_o = 1'b1;
            end
            else begin
                pc_write = 1'b1;
                IF_ID_write = 1'b1;
                IF_ID_flush = 1'b0;
                ID_EX_flush = 1'b0;
                EX_MEM_flush= 1'b0;
                stall_o = 1'b0;
            end
        end
    end

endmodule


