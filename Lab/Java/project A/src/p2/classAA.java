//Topic 2.3
package p2;
import p1.*;
public class classAA extends ClassA{
    public static void main(String[] args){
        System.out.println("Package 2 -> Class AA (Subclass of Class A) -> main()");  
        ClassA.pub();
        ClassA.prot();
        //ClassA.def(); // not visilble
        //ClassA.pvt(); // not visible
   } 
}
class classBB{
    
    public static void main(String[] args) {
        System.out.println("Package 2 -> Class BB -> main()");
        ClassA.pub();
        //ClassA.prot(); // not visible
        //ClassA.def(); // not visilble
        //ClassA.pvt(); // not visible

    }
}
