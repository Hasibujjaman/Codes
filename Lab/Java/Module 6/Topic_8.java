//Topic 8
import java.util.ArrayList;

public class Topic_8 {
    public static void main(String [] args){
        ArrayList <Integer> al = new ArrayList<>();
            al.add(10);
            al.add(50);
            al.add(70);
            al.add(30);
            System.out.println(al);
            al.add(0,60);
            System.out.println(al);
            System.out.println(al.get(1));
            al.remove(2);
            System.out.println(al);
            al.sort(null);
            for(Integer i: al){
                System.out.print(" "+i);
            }
            System.out.println();
            al.clear();
            System.out.println(al);
    }
}
