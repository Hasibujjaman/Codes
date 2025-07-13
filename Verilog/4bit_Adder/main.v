module FourBitAdder(
    input [3:0] A, // 4-bit input A
    input [3:0] B, // 4-bit input B
    input Cin,     // Carry-in
    output [3:0] Sum, // 4-bit output sum
    output Cout       // Carry-out
);

// Internal signals
wire [3:0] carry; // Internal carry signals

// Full Adder instances
FullAdder FA0(.A(A[0]), .B(B[0]), .Cin(Cin), .Sum(Sum[0]), .Cout(carry[0]));
FullAdder FA1(.A(A[1]), .B(B[1]), .Cin(carry[0]), .Sum(Sum[1]), .Cout(carry[1]));
FullAdder FA2(.A(A[2]), .B(B[2]), .Cin(carry[1]), .Sum(Sum[2]), .Cout(carry[2]));
FullAdder FA3(.A(A[3]), .B(B[3]), .Cin(carry[2]), .Sum(Sum[3]), .Cout(Cout));

endmodule

module FullAdder(
    input A,     // First input
    input B,     // Second input
    input Cin,   // Carry-in
    output Sum,  // Sum
    output Cout  // Carry-out
);

assign {Cout, Sum} = A + B + Cin;

endmodule
