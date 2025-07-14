//Topic 3
public class Topic_3{
    public static void main(String[] args) {
        System.out.println("Inside private method containing class");
        Sum();
    }
    private static void Sum(){
        int x = 5, y = 10;
        System.out.println(x+y);
    }

}

class A{
    public static void main(String[] args){
        System.out.println("Inside a different class");
        //Sum(); not visible
    }
}
