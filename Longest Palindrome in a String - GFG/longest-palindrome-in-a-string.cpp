//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ispalin(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j] && ispalin(i + 1, j - 1, s, dp)) return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
    string longestPalin (string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int max_len = 0, ind = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(ispalin(i, j, s, dp) && max_len < (j - i + 1)) {
                    ind = i;
                    max_len = j - i + 1;
                }
            }
        }
        return s.substr(ind, max_len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends