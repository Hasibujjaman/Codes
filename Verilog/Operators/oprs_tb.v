module stimulus;
    reg [3:0] A;
    reg [3:0] B;
    reg [3:0] C;
    reg [3:0] D;
    wire [3:0] Arithmetic;
    wire [3:0] Shift;
    wire [3:0] Relational;
    wire [3:0] Equality;
    wire [3:0] Bitwise;
    wire [3:0] Reduction;
    wire [3:0] Logical;
    wire [3:0] Concatenation;
    wire [3:0] Conditional;
    // Instantiate the decoder
oprs uut (
    .A(A),
    .B(B),
    .C(C),
    .D(D),
    .Arithmetic(Arithmetic),
    .Shift(Shift),
    .Relational(Relational),
    .Equality(Equality),
    .Bitwise(Bitwise),
    .Reduction(Reduction),
    .Logical(Logical),
    .Concatenation(Concatenation),
    .Conditional(Conditional)
);

initial begin
        $dumpfile("oprs_tb.vcd");
        $dumpvars(0, stimulus);

        A = 4'b1100;
        B = 4'b0110;
        C = 4'b0010;
        D = 4'b1100;
        #20;
end

initial begin
    // Display the output
    $monitor("A = %4b, B = %4b, C = %4b, D = %4b\n", A, B, C, D,
         "(Arithmetic) B+C = %4b,\n(Shift) B>>C = %4b,\n(Relational) A > B = %4b\n", Arithmetic, Shift, Relational,
         "(Equality) A == D = %4b,\n(Bitwise) B & C = %4b,\n(Reduction) |B = %4b\n",  Equality, Bitwise, Reduction,
         "(Logical) (A > B) || (A > D) = %4b,\n(Concatenation) {C[1:0], D[3:2]} = %4b,\n(Conditional) (A>B) ? A : B = %4b\n", Logical, Concatenation, Conditional);
end

endmodule
