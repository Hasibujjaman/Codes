// Topic 2.1
package p1;


public class ClassA {
    public static void main(String [] args){
        System.out.println("Package 1 -> Class A -> main");
        pub();
        prot();
        def();
        pvt();
        
    }
    public static void pub(){
        System.out.println("Class A public method");
    }
    protected static void prot(){
        System.out.println("Class A protected method");
    }
    private static void pvt(){
        System.out.println("Class A private method");
    }
    static void def(){
        System.out.println("Class A default method");
    }

}
