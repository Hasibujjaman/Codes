`timescale 1ns/1ps

module FourBitAdder_tb;

// Parameters
parameter SIM_TIME = 100; // Simulation time

// Signals
reg [3:0] A, B;
reg Cin;
wire [3:0] Sum;
wire Cout;

// Instantiate the module under test
FourBitAdder UUT(
    .A(A),
    .B(B),
    .Cin(Cin),
    .Sum(Sum),
    .Cout(Cout)
);

// Stimulus generation
initial begin
    $dumpfile("FourBitAdder_tb.vcd");
    $dumpvars(0, FourBitAdder_tb);
    // Initialize inputs
    A = 4'b0000;
    B = 4'b0000;
    Cin = 1'b0;

    // Apply test vectors
    #10 A = 4'b0001; B = 4'b0001; Cin = 1'b0;
    #10 A = 4'b0010; B = 4'b0010; Cin = 1'b0;
    #10 A = 4'b0100; B = 4'b0100; Cin = 1'b0;
    #10 A = 4'b1000; B = 4'b1000; Cin = 1'b0;

    // End of simulation
    #10 $finish;
end

// Display results
always @* begin
    $display("Time=%0t: A=%b, B=%b, Cin=%b, Sum=%b, Cout=%b",
             $time, A, B, Cin, Sum, Cout);
end

endmodule
