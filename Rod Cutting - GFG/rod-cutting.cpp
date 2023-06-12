//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int *a,int n,int length,int idx , vector<vector<int>>&dp){
      if(idx>=n) return 0;
      
      
      if(dp[idx][length]!=-1) return dp[idx][length];
      int inc=INT_MIN,repeat=INT_MIN;
      
      if(length>idx)  {
      inc=solve(a,n,length-idx-1,idx+1,dp)+a[idx];
      repeat=solve(a,n,length-idx-1,idx,dp)+a[idx];
      }
      
      int  exc=solve(a,n,length,idx+1,dp);
      return  dp[idx][length]= max(repeat,max(inc,exc));
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));           
        return solve(price,n,n,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends