import java.io.*;
import java.util.*;

public class MaxProfitSoFar {
    
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);

        System.out.println("Enter No. of days(size of array)");

        int N = sc.nextInt();
        int[] prices = new int[N];

        System.out.println("Enter Stock prices on each day");


        for(int i=0; i<N; i++){
            prices[i]= sc.nextInt();
        }
        System.out.println(maxProfit(prices));

        sc.close();
    }

    public static int maxProfit(int[] prices){
        int minPriceSoFar= Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price: prices){
            minPriceSoFar= Math.min(minPriceSoFar, price);
        
        int profit = price - minPriceSoFar;
        System.out.println(" maximum profit you can achieve");

        maxProfit= Math.max(maxProfit,profit);
    
        }
        return maxProfit;
    }

    
}
