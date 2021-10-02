import java.util.*;
public class LeaderElement {

    public static List<Integer> leaderElements(int[] a) {
        int n = a.length;
        List<Integer> res = new ArrayList<>();      //stores the leader element
        int largest = a[n-1];       //store the largest element so far
        res.add(largest);
        for(int i = n-1; i >= 0; i--){
            if(a[i] > largest) {
                res.add(a[i]);
                largest = a[i];
            }
        }
        Collections.reverse(res);
        return res;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter size of the array: ");
        int n = scan.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements: ");
        for(int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }

        System.out.println("Leader elements are: " + leaderElements(arr));
    }
}
