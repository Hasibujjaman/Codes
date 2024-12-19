import java.awt.Point;

public class test {
    static int a;
    int b;
    public static void main(String[] args) {
        Circle c1 = new Circle(new Point(4, 2), 3);
        //Circle c2 = new Circle(new Point(4, 2), 6);
        System.out.println("Center=" + c1.getCenter());
        System.out.println("Area=" + c1.Area());
        System.out.println("a = "+a);
        System.out.println("count = "+Circle.get_count());

    }
    public void getb(){
        System.out.println("b = "+b);
    }   
}

class Circle {
    Point c;
    int r;
    static int count = 0;

    public Circle(Point c, int r) {
        this.c = c;
        this.r = r;
        count++;
    }

    double Area() {
        return 2 * 3.14 * r;
    }

    Point getCenter() {
        return c;
    }
    static int get_count(){
        return count;
    }
}