//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Driverclass {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            System.out.println(new BlackAndWhite().numOfWays(N, M));
        }
    }
}
// } Driver Code Ends


class BlackAndWhite
{
    //Function to find out the number of ways we can place a black and a 
    //white Knight on this chessboard such that they cannot attack each other.
    static boolean isvalid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
    static long numOfWays(int m, int n)
    {
        // add your code here
        long ans=0,mod=1000000007,c=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isvalid(i+2,j+1,m,n)) c++;
                if(isvalid(i+2,j-1,m,n)) c++;
                if(isvalid(i-2,j+1,m,n)) c++;
                if(isvalid(i-2,j-1,m,n)) c++;
                if(isvalid(i+1,j+2,m,n)) c++;
                if(isvalid(i+1,j-2,m,n)) c++;
                if(isvalid(i-1,j+2,m,n)) c++;
                if(isvalid(i-1,j-2,m,n)) c++;
                ans=(ans%mod+(m*n)-c)%mod;
                c=1;
            }
        }
        return ans%mod;
    }
}