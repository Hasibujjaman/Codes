// Topic 1
import java.util.Scanner;
public class Topic_1{
    public static void main(String[] args) {
        System.out.println("Name: MD. HASIBUJJAMAN CHOWDHURY EMON");
        System.out.println("Address: Baliapukur, Rajshahi");
        int a,b;
         Scanner input = new Scanner(System.in);
            System.out.println("Enter two numbers: ");
            a = input.nextInt();
            b = input.nextInt();
            System.out.println("Bigger number: " +Large(a,b));
            int ax[] = new int[10];
            System.out.println("Enter 10 array elements:");
            for(int i = 0; i < 10; i++){
                ax[i] = input.nextInt();
            }
            int large,small,sum;
            large = small = sum = ax[0];
            for(int i = 1; i < 10; i++){
                if(ax[i] > large) large = ax[i];
                if(ax[i] < small) small = ax[i];
                sum += ax[i];
            }
            double avg = sum / 10.0;
            System.out.println("Largest element: " +large + " Smallest elemet: " +small + " Average: " +avg);
        

    }

    public static int Large(int x, int y){
        if(x > y) return x;
        else return y;
    }

}