import java.util.Scanner;
public class Kadane
{
    public int maxSequenceSum(int[] arr)
    {        
        int maxSoFar = arr[0], maxEndingHere = arr[0];
 
        for (int i = 1; i < arr.length; i++)
        {
            if (maxEndingHere < 0)
                maxEndingHere = arr[i];
            else
                maxEndingHere += arr[i];
            if (maxEndingHere >= maxSoFar)
                maxSoFar = maxEndingHere;
        }
        return maxSoFar;
    }    
    public static void main (String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Kadane Algorithm Test\n");
        Kadane k = new Kadane();
 
        System.out.println("Enter size of array :");
        int N = scan.nextInt();
        System.out.println("Enter "+ N +" elements");
        int[] arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = scan.nextInt();
        int sum = k.maxSequenceSum(arr);
        System.out.println("\nMaximum Sequence sum = "+ sum);
 
    }
}
