import java.util.*;

public class NextPermutation {

    private static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            swap(arr, start++, end--);
        }
    }

    // Helper method to swap two elements
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    public static void main(String[] args){
         Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] arr = new int[n];
        
        for(int i=0 ; i<n ; i++){
            arr[i]=sc.nextInt();
        }

        // Find the pivot index
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                pivot = i;
                break;
            }
        }
        sc.close();
  
        // If pivot point does not exist, reverse the whole array
        if (pivot == -1) {
            reverse(arr, 0, n - 1);
            return ;
        }

        // Find the element from the right that is greater than pivot
        for (int i = n - 1; i > pivot; i--) {
            if (arr[i] > arr[pivot]) {
                swap(arr, i, pivot);
                break;
            }
        }

        // Reverse the elements from pivot + 1 to the end
        reverse(arr, pivot + 1, n - 1);
        
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}

    
