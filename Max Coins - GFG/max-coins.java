//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;

class GFG implements Runnable
{
    public static void main(String args[])throws IOException
    {
        new Thread(null, new GFG(), "whatever", 1<<26).start();
    }
    public void run()
    {
        try{
            BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out=new PrintWriter(System.out);
            int t=Integer.parseInt(in.readLine());
            while(t-->0){
                int n=Integer.parseInt(in.readLine().trim());
                int a[][]=new int[n][3];
                for(int i=0;i<n;i++){
                    String s[]=in.readLine().trim().split(" ");
                    a[i][0]=Integer.parseInt(s[0]);
                    a[i][1]=Integer.parseInt(s[1]);
                    a[i][2]=Integer.parseInt(s[2]);
                }
                Solution ob=new Solution();
                out.println(ob.maxCoins(n,a));
            }
            out.close();
        }catch(Exception e){
            ;
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution{
    public static int solve(int id, int count, int [][] ranges, int [][] dp) {
        if(count == 0 || id == ranges.length) return 0;
        if(dp[id][count] != -1) return dp[id][count];
        int inc = ranges[id][2];
        int lo = id + 1, hi = ranges.length - 1, idx = ranges.length;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(ranges[mid][0] >= ranges[id][1]) {idx = mid; hi = mid - 1;}
            else lo = mid + 1;
        }
        inc += solve(idx, count - 1, ranges, dp);
        int exc = solve(id + 1, count, ranges, dp);
        return dp[id][count] = Math.max(inc, exc);
    }
    public static int maxCoins(int n,int ranges[][])
    {
        Arrays.sort(ranges,new Comparator<int[]>(){
            public int compare(int first[],int second[]){
                if(first[0]==second[0])
                return first[1]-second[1];
                else
                return first[0]-second[0];
            }
        });
        int [][] dp = new int[n][3];
        for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) dp[i][j] = -1;
        return solve(0, 2, ranges, dp);
    }
}