module Encoder_4to2_priority(
    input [3:0] Y,
    output reg [1:0] A
);

always @*
begin 
    if(Y[3])
    begin
        A[0] = 1;
        A[1] = 1;
    end
    else if(Y[2]) begin
        A[1] = 1;
        A[0] = 0;
    end
    else if(Y[1]) begin
        A[1] = 0;
        A[0] = 1;
    end
    else begin
        A[1] = 0;
        A[0] = 0;
    end
end
endmodule
    