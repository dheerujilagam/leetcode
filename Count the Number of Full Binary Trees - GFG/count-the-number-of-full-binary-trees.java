//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int a[] = new int[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }
            
            Solution obj = new Solution();
            System.out.println(obj.numoffbt(a, n));
            
        }
	}
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public static int numoffbt(int arr[], int n)
    {
         // Your code goes here
         int mn=1000000007,mx=0,mod=1000000007;
         for(int i=0;i<n;i++){
             mn=Math.min(arr[i],mn);
             mx=Math.max(arr[i],mx);
         }
         int []val=new int[mx+1];
         for(int i=0;i<n;i++)
            val[arr[i]]=1;
         int ans=0;
         for(int i=mn;i<=mx;i++){
             if(val[i]!=0){
                 for(int j=i+i;j<=mx && (j/i)<=i;j+=i){
                     if(val[j]!=0){
                         val[j]+=(val[i]*val[j/i]);
                         if((j/i)!=i) val[j]+=(val[i]*val[j/i]);
                     }
                 }
             }
             ans+=(val[i]%mod);
         }
         return (ans%mod);
    }
}