module decoder_2to4_with_enable(
    input wire E, // Enable input
    input wire A,
    input wire B,
    output wire Y0,
    output wire Y1,
    output wire Y2,
    output wire Y3
);
    assign Y0 = E & ~A & ~B;
    assign Y1 = E & ~A & B;
    assign Y2 = E & A & ~B;
    assign Y3 = E & A & B;
endmodule
