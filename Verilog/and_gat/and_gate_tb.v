module and_gate_tb;
    reg a, b;
    wire y;
    and_gate and_gate_inst (
        .a(a),
        .b(b),
        .y(y)
    );
    initial begin
        $display("Testing AND gate");
        $dumpfile("dump.vcd");
        $dumpvars(0, and_gate_tb);
        a = 0; b = 0;
        #10 $display("a=%b, b=%b, y=%b", a, b, y);
        a = 0; b = 1;
        #10 $display("a=%b, b=%b, y=%b", a, b, y);
        a = 1; b = 0;
        #10 $display("a=%b, b=%b, y=%b", a, b, y);
        a = 1; b = 1;
        #10 $display("a=%b, b=%b, y=%b", a, b, y);
        $finish;
    end

endmodule
