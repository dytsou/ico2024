module hazard_ctrl #(parameter DWIDTH = 32)
    (
        input [2:0]        branch,      // branch signal
        input [1:0]        memory_read, // memory read signal
        input [4:0]        EX_rdst_id,    // EX.rt
        input [4:0]        ID_rs_id,    // ID.rs
        input [4:0]        ID_rt_id,    // ID.rt

        output reg         pc_write,    // PC write signal
        output reg         IF_ID_write,   // register file write signal
        output reg         IF_ID_flush,    
        output reg         ID_EX_flush,    
        output reg         EX_MEM_flush
    );

    always @(*) begin
        if(branch != 3'b000) begin // branch hazard
            pc_write = 1'b1;
            IF_ID_write = 1'b1;
            IF_ID_flush = 1'b1;
            ID_EX_flush = 1'b1;
            EX_MEM_flush= 1'b1;
        end
        else begin
            if((memory_read[0] && (EX_rdst_id == ID_rs_id || EX_rdst_id == ID_rt_id)) || memory_read[1]) begin // load-use hazard
                pc_write = 1'b0;
                IF_ID_write = 1'b0;
                IF_ID_flush = 1'b0;
                ID_EX_flush = 1'b1;
                EX_MEM_flush= 1'b0;
            end
            else begin
                pc_write = 1'b1;
                IF_ID_write = 1'b1;
                IF_ID_flush = 1'b0;
                ID_EX_flush = 1'b0;
                EX_MEM_flush= 1'b0;
            end
        end
    end

endmodule


