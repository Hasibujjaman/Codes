module counter(clk,q);
input clk;
output [4:0] q;

register uut(clk,q);

endmodule



module register(clk,q_reg);

input wire clk;
output reg [4:0] q_reg;

reg [4:0] d_reg = 0; // counting will start from the value of d

always @(posedge clk)
begin
q_reg = d_reg;
d_reg = d_reg + 1;
end

endmodule