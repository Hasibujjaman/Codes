module counter
(
    input wire clk,
    output [4:0] q
);
wire [4:0] d_temp, q_temp;
register register_circuit1 (clk, d_temp, q_temp);
addOne adder_circuit1 (q_temp, d_temp);
assign q = q_temp;

endmodule