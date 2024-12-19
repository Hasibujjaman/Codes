module mux_example(
  input [1:0] sel,
  input  [3:0] i,
  output reg y);
    
  always @(*) begin
    case(sel)
      2'h0: y = i[0];
      2'h1: y = i[1];
      2'h2: y = i[2];
      2'h3: y = i[3];
      default: $display("Invalid sel input");
    endcase
  end
endmodule