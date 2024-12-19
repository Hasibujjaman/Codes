module counter(clk,q);
input clk;
output [4:0] q;

reg [4:0] d = 0; // counting will start from the value of d

register uut(clk,d,q);

//this always block presumably executes after the always block in resigter module 
always @(posedge clk)
begin
d <= d+1;
//d = d+1;
end


endmodule


module register(clk,d_reg,q_reg);

input wire clk;
input wire [4:0] d_reg;
output reg [4:0] q_reg;

always @(posedge clk)
begin
q_reg <= d_reg;
end

endmodule