module decoder_3to8(
    input  [2:0] A,
    output reg [7:0] Y
);

always @(*) begin
case(A)
3'b000: begin Y=8'b00000001; end
3'b001: begin Y=8'b00000010; end
3'b010: begin Y=8'b00000100; end
3'b011: begin Y=8'b00001000; end
3'b100: begin Y=8'b00010000; end
3'b101: begin Y=8'b00100000; end
3'b110: begin Y=8'b01000000; end
3'b111: begin Y=8'b10000000; end
endcase
end

endmodule

