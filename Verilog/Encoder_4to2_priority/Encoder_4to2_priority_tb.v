module tb;
  reg [3:0] Y;
  wire [1:0] A;
  
  // instantiate the model: creating 
  // instance for block diagram 
  Encoder_4to2_priority uut (Y,A);
  initial begin
      // monitor is used to display the information. 
      $monitor("Y=%b | A=%b",Y,A);
      // since en and i are input values, 
      // provide values to en and i. 
       Y=0;#5
       Y=1;#5
       Y=4'b001x;#5
       Y=4'b01xx;#5
       Y=4'b1xxx;#5
      $finish;
    end
endmodule