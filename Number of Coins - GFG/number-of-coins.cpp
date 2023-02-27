//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int v, int m, int coins[], vector<int> &dp) {
	    if(v == 0)
	        return 0;
	    if(dp[v] != -1)
	        return dp[v];
	    int val = INT_MAX; 
	    for(int i = 0; i < m; i++){
	        if(v - coins[i] >= 0){
	            int n = solve(v - coins[i], m, coins, dp);
	            if(n != INT_MAX)
	                val = min(n + 1, val);
	        }
	    }
	    return dp[v] = val;
	}
	
	int minCoins(int coins[], int m, int v) { 
	    // Your code goes here
	    vector<int> dp(v + 1, -1);
	    int val = solve(v, m, coins, dp);
	    if(val != INT_MAX)
	        return val;
	    return -1;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends