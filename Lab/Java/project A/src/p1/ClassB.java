// Topic 2.2
package p1;

public class ClassB {
    public static void main(String[] args) {
        System.out.println("Package 1 -> class B ->main()");
        ClassA.pub();
        ClassA.prot();
        ClassA.def();
        //ClassA.pvt(); not visible outside own class
        ClassB ob = new ClassB();
        ob.X();
    }
    private void X(){
        System.out.println("Non static method");
    }
}
