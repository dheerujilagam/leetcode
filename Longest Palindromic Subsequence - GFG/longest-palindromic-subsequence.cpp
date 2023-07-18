//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(int l, int r, string &s, vector<vector<int>> &dp) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = 2 + solve(l + 1, r - 1, s, dp);
        return dp[l][r] = max(solve(l + 1, r, s, dp), solve(l, r - 1, s, dp));
    }
    int longestPalinSubseq(string s) {
        //code here
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n - 1, s, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends