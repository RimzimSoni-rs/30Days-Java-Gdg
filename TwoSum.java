
    import java.util.*;

    public class TwoSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values
        String[] numsStr = scanner.nextLine().trim().split(" ");
        int[] nums = new int[numsStr.length];
        for (int i = 0; i < numsStr.length; i++) {
            nums[i] = Integer.parseInt(numsStr[i]);
        }
        
        int target = scanner.nextInt();
        
        // Call the twoSum method
        int[] result = twoSum(nums, target);
        
        // If the result is an empty array, print "{}"
        if (result.length == 0) {
            System.out.println("{}");
        } else {
            // Print the result in the required format
            System.out.println("{" + result[0] + ", " + result[1] + "}");
        }
        
        scanner.close();
    }
    
    public static int[] twoSum(int[] nums, int target) {
        // HashMap to store numbers and their indices
        Map<Integer, Integer> numMap = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                // Return the indices of the two numbers that sum up to the target
                return new int[] { numMap.get(complement), i };
            }
            numMap.put(nums[i], i);
        }
        
        // If no solution is found, return an empty array
        return new int[] {};  // Returning an empty array for no solution
    }
}
    

