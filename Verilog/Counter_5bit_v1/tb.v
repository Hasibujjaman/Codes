`timescale 1ns/1ns
module counter_tb;
    reg clk;
    wire [4:0] q;

counter uut (clk, q);

//generate clock
always begin
clk = ~clk;
#10;
end

initial begin
   $dumpfile("tb.vcd");
   $dumpvars(0, counter_tb);
    clk <= 0;
    #20;
    #20;
    #20;
    #20;
    #20;
    #20;
    $finish;
end

initial begin
    $monitor("clk = %b, Count = %d ", clk, q);
end
endmodule