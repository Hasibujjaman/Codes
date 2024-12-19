module register
(
    input wire clk,
    input wire [4:0] d,
    output reg [4:0] q
);
always @(posedge clk)
begin
q <= d;
end
endmodule