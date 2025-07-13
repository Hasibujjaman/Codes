//inner outer class part 2
package p1;

public class Outer {
    private int x = 20;

    class Inner {
        private int y;

        public Inner(int y) {
            this.y = y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public int getY() {
            return y;
        }

        public void sum() {
            System.out.println("inside sum=" + (x + y));
        }
    }

    public void Display() {
        Inner inner = new Inner(0);
        inner.setY(12);
        System.out.println(inner.getY());
    }
}
