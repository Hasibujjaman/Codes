//Inner outer class part 1
package p1;

public class ClassC {
    public static void main(String[] args) {
        // outer is Outer class object
        Outer outer = new Outer();
        outer.Display();
        // in is Inner class object
        Outer.Inner in = new Outer().new Inner(45);
        in.sum();
    }
}
