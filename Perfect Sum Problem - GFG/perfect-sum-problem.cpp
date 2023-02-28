//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long int mod = 1000000007;
	int solve(int i, int n, int sum, int arr[], vector<vector<int>> &dp){
	    if(sum < 0)
	        return 0;
	    if(i == n){
	        if(sum == 0)
	            return 1;
	        return 0;
	    }
	    if(dp[i][sum] != -1)
	        return dp[i][sum];
	    int in = solve(i + 1, n, sum - arr[i], arr, dp);
	    int ex = solve(i + 1, n, sum, arr, dp);
	    return dp[i][sum] = (in + ex) % mod;
	}
	
	int perfectSum(int arr[], int n, int sum) {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, n, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends