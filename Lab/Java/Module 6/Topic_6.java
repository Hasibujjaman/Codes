//Topic 6
import java.util.Arrays;
public class Topic_6 {
    public static void main(String[] args) {
        int arr[] = InitiaArray();
        int arr1[] = SortArray();
        PrintArray(arr1);
        
    }
    public static int[] InitiaArray(){
        return new int[]{3,2,1};
    }
    public static int[] SortArray(){
        int sarr[] = new int[]{5,3,1};
        Arrays.sort(sarr);
        return sarr;
    }
    public static void PrintArray(int arr[]){
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
