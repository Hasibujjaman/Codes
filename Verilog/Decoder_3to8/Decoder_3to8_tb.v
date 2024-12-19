//`timescale 1ns/1ps
module decoder_3to8_tb;
    reg [2:0] A;
    wire [7:0] Y;

    // Instantiate the decoder
    decoder_3to8 uut (
        .A(A),
        .Y(Y)
    );

    initial begin
         $dumpfile("Decoder_3to8_tb.vcd");
         $dumpvars(0, decoder_3to8_tb);

            
        // Apply test vectors
        A = 3'b000; #10;
        A = 3'b001; #10;
        A = 3'b010; #10;
        A = 3'b011; #10;
         A = 3'b100; #10;
         A = 3'b101; #10;
         A = 3'b110; #10;
         A = 3'b111; #10;
        // End simulation
        $finish;
    end

        initial begin
        // Display the output
        $monitor("A[2] = %b, A[1] = %b, A[0] = %b | Y7 = %b, Y6 = %b, Y5 = %b, Y4 = %b, Y3 = %b, Y2 = %b, Y1 %b, Y0 = %b", A[2],A[1],A[0],Y[7],Y[6],Y[5],Y[4],Y[3],Y[2],Y[1],Y[0]);
        end

endmodule
