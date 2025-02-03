import java.util.*;

class Job {
    int start, end, profit;
    
    // Constructor to initialize job details
    Job(int start, int end, int profit) {
        this.start = start;
        this.end = end;
        this.profit = profit;
    }
}

public class JobScheduling {

    // Binary Search to find the last non-conflicting job
    public static int binarySearch(Job[] jobs, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid].end <= jobs[index].start) {
                if (jobs[mid + 1].end <= jobs[index].start) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // Function to find the maximum profit by selecting non-overlapping jobs
    public static int maxProfit(int n, int[] start, int[] end, int[] profit) {
        // Create an array of jobs
        Job[] jobs = new Job[n];
        
        // Initialize the job array with start, end, and profit
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(start[i], end[i], profit[i]);
        }
        
        // Sort the jobs based on their end times
        Arrays.sort(jobs, Comparator.comparingInt(a -> a.end));

        // DP array to store the maximum profit up to each job
        int[] dp = new int[n];
        dp[0] = jobs[0].profit; // The profit from the first job

        // Loop through all jobs to calculate the maximum profit at each step
        for (int i = 1; i < n; i++) {
            // Option 1: Do not include the current job
            int includeCurrentProfit = jobs[i].profit;

            // Option 2: Include the current job and add profit of the last non-conflicting job
            int index = binarySearch(jobs, i);
            if (index != -1) {
                includeCurrentProfit += dp[index];
            }

            // Maximum profit at the i-th job will be the best of including or excluding it
            dp[i] = Math.max(dp[i - 1], includeCurrentProfit);
        }

        // The last entry in dp array will have the maximum profit
        return dp[n - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Reading the number of jobs
        int n = sc.nextInt();
        
        // Reading the start times of the jobs
        int[] start = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = sc.nextInt();
        }
        
        // Reading the end times of the jobs
        int[] end = new int[n];
        for (int i = 0; i < n; i++) {
            end[i] = sc.nextInt();
        }
        
        // Reading the profit values of the jobs
        int[] profit = new int[n];
        for (int i = 0; i < n; i++) {
            profit[i] = sc.nextInt();
        }

        // Calculate the maximum profit
        int result = maxProfit(n, start, end, profit);

        // Output the result
        System.out.println(result);
        
        sc.close();
    }
}
