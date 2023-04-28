//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Gfg {
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            
            String s[]=in.readLine().trim().split(" ");
            int n=Integer.parseInt(s[0]);
            int m=Integer.parseInt(s[1]);
            char c[][]=new char[n][m];
            for(int i=0;i<n;i++){
                s=in.readLine().trim().split(" ");
                for(int j=0;j<m;j++){
                    c[i][j]=s[j].charAt(0);
                }
            }
            Solution ob=new Solution();
            int ans[][]=ob.chefAndWells(n, m, c);

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    out.print(ans[i][j]+" ");
                }
                out.println();
            }
        }
        out.close();
    }
}
// } Driver Code Ends


//User function Template for Java
class Pair {
    int dis;
    int r;
    int c;
    Pair(int d, int row, int col) {
        this.dis = d;
        this.r = row;
        this.c = col;
    }
}
class Solution
{   
    public int[][] chefAndWells(int n,int m,char c[][])
    {
        int [][] res = new int[n][m];
        boolean [][] vis = new boolean[n][m];
        Queue<Pair> q = new ArrayDeque<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'W') {
                    vis[i][j] = true;
                    res[i][j] = 0;
                    q.add(new Pair(0, i, j));
                }
                if(c[i][j] == 'H') res[i][j] = -1;
                if(c[i][j] == '.') res[i][j] = 0;
                if(c[i][j] == 'N') {res[i][j] = 0; vis[i][j] = true;}
            }
        }
        int [][] moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.isEmpty()) {
            Pair p = q.poll();
            for(int i = 0; i < 4; i++) {
                int x = p.r + moves[i][0], y = p.c + moves[i][1];
                if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == false && (c[x][y] == 'H' || c[x][y] == '.')) {
                    if(c[x][y] == 'H') res[x][y] = (p.dis + 1) * 2;
                    vis[x][y] = true;
                    q.add(new Pair(p.dis + 1, x, y));
                }
            }
        }
        return res;
    }
}