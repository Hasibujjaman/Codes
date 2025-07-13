//`timescale 1ns/1ps
module decoder_2to4_with_enable_tb;
    reg E, A, B;
    wire Y0, Y1, Y2, Y3;

    // Instantiate the decoder
    decoder_2to4_with_enable uut (
        .E(E),
        .A(A),
        .B(B),
        .Y0(Y0),
        .Y1(Y1),
        .Y2(Y2),
        .Y3(Y3)
    );

    initial begin
         $dumpfile("Decoder_2_to_4_with_Enable_tb.vcd");
         $dumpvars(0, decoder_2to4_with_enable_tb);

            
        // Apply test vectors
        E = 0; A = 0; B = 0; #10;
        E = 0; A = 0; B = 1; #10;
        E = 0; A = 1; B = 0; #10;
        E = 0; A = 1; B = 1; #10;
        E = 1; A = 0; B = 0; #10;
        E = 1; A = 0; B = 1; #10;
        E = 1; A = 1; B = 0; #10;
        E = 1; A = 1; B = 1; #10;
        // End simulation
        $finish;
    end

        initial begin
        // Display the output
        $monitor("E = %b, A = %b, B = %b | Y0 = %b, Y1 = %b, Y2 = %b, Y3 = %b", E, A, B, Y0, Y1, Y2, Y3);
        end

endmodule
