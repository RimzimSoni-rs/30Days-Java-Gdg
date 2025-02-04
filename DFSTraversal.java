import java.util.*;

public class DFSTraversal {
    
    // Function to perform DFS traversal
    public static void DFS(int node, List<List<Integer>> adjList, boolean[] visited) {
        // Print the current node
        System.out.print(node + " ");
        
        // Mark the node as visited
        visited[node] = true;
        
        // Visit all adjacent nodes
        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                DFS(neighbor, adjList, visited);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of vertices (V) and edges (E)
        int V = sc.nextInt();
        int E = sc.nextInt();
        
        // Create an adjacency list for the graph
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
        
        // Read the edges and populate the adjacency list
        for (int i = 0; i < E; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adjList.get(a).add(b);
            adjList.get(b).add(a); // Since the graph is undirected
        }
        
        // Array to track visited vertices
        boolean[] visited = new boolean[V];
        
        // Start DFS traversal from vertex 0, handle disconnected graphs
        if (V > 0) {
            DFS(0, adjList, visited);
        }
        
        // Print a newline at the end
        System.out.println();
        
        sc.close();
    }
}
