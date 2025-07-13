//Topic 1
class A {
    int x;

    public A() {
        x = 0;
    }

    public A(int x) {
        this.x = x;
    }

    public int getX() {
        return (x + 10);
    }
}

class B extends A {
    int x = 20;

    public B() {
        super(100);
    }

    public int Ax() {
        return super.x;
    }

    public int getX() {
        return super.getX();
    }

    public B(int x){
        super(1000);
    }
    public int getx() {
        return (x + 10);
    }
}

public class Topic_1 {
    public static void main(String[] args) {
        B test = new B();
        System.out.println("the x of class A is ; " + test.Ax());
        System.out.println("The getx of A is : " + test.getX());
        System.out.println("The x of class B : " + test.x);
        System.out.println("The getx of classs B : " + test.getx());
    }
}
