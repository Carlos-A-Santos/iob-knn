`timescale 1ns/1ps
`include "iob_lib.vh"

module knn_core
   (
    `INPUT(KNN_ENABLE, 1),    
    `INPUT(clk, 1),
    `INPUT(rst, 1),
    `INPUT(en, 1),
    `INPUT(x, 32),
    `OUTPUT(y_high, 32),
    `OUTPUT(y_low, 32)
    );
    

   `SIGNAL(Y, 64)
   `SIGNAL(Y_HIGH, 32)
   `SIGNAL(Y_LOW, 32)
   `SIGNAL(reg_out_1, 32)
   `SIGNAL(reg_out_2, 32)
   `SIGNAL(reg_out_3, 32)
   `SIGNAL(reg_out_4, 32)

   `REG_RE(clk, rst, 0, en, reg_out_1, x)
   `REG_RE(clk, rst, 0, en, reg_out_2, reg_out_1)
   `REG_RE(clk, rst, 0, en, reg_out_3, reg_out_2)

   `COMB begin

   		Y = x*reg_out_1+reg_out_2*reg_out_3;
   		Y_LOW = Y[31:0];
		Y_HIGH = Y[63:32];
   	end

   	`SIGNAL2OUT(y_low, Y_LOW)
   	`SIGNAL2OUT(y_high, Y_HIGH)

endmodule

