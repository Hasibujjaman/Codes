module d_ff (
   input wire clk,
   input wire d,
   output reg q
);
always @(posedge clk) //posedge means positive edge begin
begin
q <= d;
end
endmodule