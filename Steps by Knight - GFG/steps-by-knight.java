//{ Driver Code Starts
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
            int N = Integer.parseInt(br.readLine().trim());
            String[] S1 = br.readLine().trim().split(" ");
            String[] S2 = br.readLine().trim().split(" ");
            int[] KnightPos = new int[2];
            int[] TargetPos = new int[2];
            for(int i = 0; i < 2; i++){
                KnightPos[i] = Integer.parseInt(S1[i]);
                TargetPos[i] = Integer.parseInt(S2[i]);
            }
            Solution obj = new Solution();
            int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
            System.out.println(ans);
       }
    }
}

// } Driver Code Ends

class Pair{
    int x,y,dis;
    Pair(int dis, int x, int y){
        this.x = x;
        this.y = y;
        this.dis = dis;
    }
}


class Solution
{
    private int[][] moves = {{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
    
    public int minStepToReachTarget(int[] kp, int[] tp, int n) {
        int stx=kp[0]-1,sty=kp[1]-1;
        int endx=tp[0]-1,endy=tp[1]-1;
        int[][] vis = new int[n][n];
        Queue<Pair> pq = new LinkedList<>();
        pq.add(new Pair(0,stx,sty));
        vis[stx][sty]=1;
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            int count=p.dis;
            int i=p.x,j=p.y;
            if(i==endx && j==endy)
                return count;
            for(int k=0;k<8;k++){
                int x=i+moves[k][0],y=j+moves[k][1];
                if(x<0 || y<0 || x>=n || y>=n || vis[x][y]!=0)
                    continue;
                vis[x][y]=1;
                pq.add(new Pair(count+1,x,y));
            }
        }
        return -1;
    }

}