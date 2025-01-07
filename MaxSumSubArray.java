import java.util.Scanner;
public class MaxSumSubArray {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array
        int n = scanner.nextInt();
        
        // Initialize the array and read its elements
        int[] arr = new int[n];
        boolean allNegative = true; // To check if all elements are negative
        
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
            if (arr[i] >= 0) {
                allNegative = false; // If any element is non-negative
            }
        }
        
        // If all elements are negative, print "Invalid Input"
        if (allNegative) {
            System.out.println("Invalid Input");
            return;
        }
        
        // Applying Kadane's algorithm to find the maximum sum of contiguous sub-array
        int maxSoFar = arr[0];
        int maxEndingHere = arr[0];
        
        for (int i = 1; i < n; i++) {
            maxEndingHere = Math.max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }
        
        // Output the maximum sum found
        System.out.println(maxSoFar);
    }
}

