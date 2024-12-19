//Topic 7
import java.util.Arrays;

public class Topic_7 {
    public static void main(String[] args) {
        int arr[] = new int[]{1,2,3,4,5};
        System.out.println(Arrays.toString(arr));
        System.out.println(FindBig(arr));

    }
    public static int FindBig(int ...ax){
        int big = ax[0];
        for(int i = 1; i < 4; i++){
            if(ax[i]>big) big = ax[i];
        }
        return big;
    }
}
