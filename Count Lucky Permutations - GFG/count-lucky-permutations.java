//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            int N = Integer.parseInt(S[0]);
            int M = Integer.parseInt(S[1]);

            int arr[] = new int[(int)(N)];
int i=0;
            String inputLine2[] = read.readLine().trim().split(" ");
            for (i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(inputLine2[i]);
            }
            int graph[][] = new int[M][2];
            for (i = 0; i < M; i++) {
                String S1[] = read.readLine().trim().split(" ");
                graph[i][0] = Integer.parseInt(S1[0]);
                graph[i][1] = Integer.parseInt(S1[1]);
            }

            Solution ob = new Solution();
            System.out.println(ob.luckyPermutations(N, M, arr, graph));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long luckyPermutations(int n, int m, int arr[], int[][] graph) {
        // Code here
        long[][] dp = new long[n][(1 << n)];
        boolean [][]adj=new boolean[n][n];
        for(int i=0;i<m;i++){
            adj[graph[i][0]-1][graph[i][1]-1]=true;
            adj[graph[i][1]-1][graph[i][0]-1]=true;
        }
        
        for(int i=0;i<n;i++){
            dp[i][1<<i]=1;
        }
        
        for(int k=1;k<(1<<n);k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && adj[arr[i]-1][arr[j]-1] && arr[i]!=arr[j] && (1&(k>>j))>0){
                        dp[i][k]+=dp[j][k^(1<<i)];
                    }
                }
            }
        }
        long c=0;
        for(int i=0;i<n;i++){
            c+=dp[i][(1<<n)-1];
        }
        return c;
    }
}
