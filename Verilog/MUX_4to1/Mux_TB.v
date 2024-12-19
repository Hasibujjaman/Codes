module tb;
  reg [1:0] sel;
  reg [3:0] i;
  wire y;
  
  mux_example uut(sel,i,y);
  
  initial begin
    $monitor("sel = %b -> i3 = %0b, i2 = %0b ,i1 = %0b, i0 = %0b -> y = %0b", sel,i[3],i[2],i[1],i[0], y);
    {i[3],i[2],i[1],i[0]} = 4'h5;
    repeat(6) begin
      sel = $random;
      #5;
    end
  end
endmodule