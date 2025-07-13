//Topic 4
public class Topic_4 {
    static int x = 10;
    int y = 20;
    
    public void Sum(){
        //int sum = x + y;
        System.out.println("Non static method initiated");
    }
    public static void Add(){
        System.out.println("Static method initiated");
    }
    public static void main(String[] args){
        System.out.println("Static main() ->");
        System.out.println("Static member x = " + x);
        Add();
        //System.out.println("Non static member y = " + y); // Static method can't refer to a non static member/method- 
        //o.Sum();                                            // if object is not created first
    }

}
