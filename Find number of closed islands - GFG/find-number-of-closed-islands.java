//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] str = br.readLine().trim().split(" ");
            int N = Integer.parseInt(str[0]);
            int M = Integer.parseInt(str[1]);
            int[][] matrix = new int[N][M];
            for(int i=0; i<N; i++)
            {
                String[] s = br.readLine().trim().split(" ");
                for(int j=0; j<M; j++)
                    matrix[i][j] = Integer.parseInt(s[j]);
            }
            
            Solution obj = new Solution();
            System.out.println(obj.closedIslands(matrix, N, M));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public void dfs(int i, int j, int n, int m, int[][] mat) {
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 0) return ;
        mat[i][j] = 0;
        dfs(i - 1, j, n, m, mat);
        dfs(i + 1, j, n, m, mat);
        dfs(i, j - 1, n, m, mat);
        dfs(i, j + 1, n, m, mat);
        return ;
    }
    
    public int closedIslands(int[][] mat, int n, int m)
    {
        // Code here
        int no_of_islands = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    dfs(i, j, n, m, mat);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    no_of_islands++;
                    dfs(i, j, n, m, mat);
                }
            }
        }
        return no_of_islands;
    }
}