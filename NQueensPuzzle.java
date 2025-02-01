import java.util.Scanner;

public class NQueens {

    // Function to check if a queen can be placed at (row, col)
    private static boolean isSafe(int row, int col, int[] queens) {
        for (int i = 0; i < row; i++) {
            int queenCol = queens[i];
            // Check if queens are in the same column or on the same diagonal
            if (queenCol == col || Math.abs(queenCol - col) == Math.abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    // Function to solve the N Queens problem using backtracking
    private static void solveNQueens(int row, int N, int[] queens) {
        if (row == N) {
            // Solution found, print the board
            printBoard(N, queens);
            return;
        }

        // Try placing queens in all columns one by one
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col, queens)) {
                queens[row] = col; // Place the queen in the current row
                solveNQueens(row + 1, N, queens); // Recursively place queens in the next row
            }
        }
    }

    // Function to print the board
    private static void printBoard(int N, int[] queens) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (queens[i] == j) {
                    System.out.print("1 "); // Queen found at (i, j)
                } else {
                    System.out.print("0 "); // Empty cell
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        if (N == 2 || N == 3) {
            System.out.println("NO");
        } else {
            int[] queens = new int[N]; // Array to store the column positions of queens
            solveNQueens(0, N, queens); // Start solving from row 0
        }
        scanner.close();
    }
}
