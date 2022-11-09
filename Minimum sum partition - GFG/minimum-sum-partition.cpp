//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public: 
    int solve(vector<vector<int>>&dp, int arr[], int prefix, int suffix, int i, int n){
        if(i>=n)
            return abs(prefix-suffix);
        if(dp[i][prefix]!=-1)
            return dp[i][prefix];
        int x=solve(dp,arr,prefix+arr[i],suffix-arr[i],i+1,n);
        int y=solve(dp,arr,prefix,suffix,i+1,n);
        return dp[i][prefix]=min(x,y);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int suffix=accumulate(arr,arr+n,0);
	    vector<vector<int>>dp(n,vector<int>(suffix,-1));
	    return solve(dp,arr,0,suffix,0,n);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends