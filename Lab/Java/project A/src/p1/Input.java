package p1;

//import java.util.Scanner;

public abstract class Input {
    String name = "Person";

    public Input() {
        System.out.println(name);
    }

    public Input(String s) {
        name = s;
        System.out.println(name);
    }
    public abstract void kf();
}
class B{}

class Employee extends Input{
    int a;
    String name = "Employee";

    public Employee() {
        super("Rana");
        System.out.println(name);
        System.out.println(super.name);
    }

    public  void kf(){

    }
    

    public static void main(String[] args) {
       // Employee e = new Employee();
       // Scanner scan = new Scanner(System.in);
       // int i = scan.nextInt();
    }
}
interface A{
    public void mm();
    public abstract void nn();

}