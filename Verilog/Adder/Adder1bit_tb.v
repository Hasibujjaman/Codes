`timescale 1ns/1ps
module Adder1bit_tb();
    reg A;
    reg B;
    reg Cin;
    wire S;
    wire Cout;

    Adder1bit UUT(A, B, Cin, S, Cout);
    initial begin
         $dumpfile("Adder1bit_tb.vcd");
         $dumpvars(0, Adder1bit_tb);

        Cin = 1'b0;
        A = 1'b0;
        B = 1'b0;
        #20;
        Cin = 1'b0;
        A = 1'b0;
        B = 1'b1;
        #20;
        Cin = 1'b0;
        A = 1'b1;
        B = 1'b0;
        #20;
        Cin = 1'b0;
        A = 1'b1;
        B = 1'b1;
        #20;
        Cin = 1'b1;
        A = 1'b0;
        B = 1'b0;
        #20;
        Cin = 1'b1;
        A = 1'b0;
        B = 1'b1;
        #20;
        Cin = 1'b1;
        A = 1'b1;
        B = 1'b0;
        #20;
        Cin = 1'b1;
        A = 1'b1;
        B = 1'b1;

        $finish;
    end
    initial begin   
        $monitor("A = %d, B = %d, Cin = %d, S = %d, Cout = %d\n",A, B,Cin, S, Cout);
    end
endmodule
