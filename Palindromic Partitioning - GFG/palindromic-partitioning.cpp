//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int st, int end, string &s, vector<vector<int>> &dp) {
        if (st >= end) return 1;
        if (dp[st][end] != -1) return dp[st][end];
        return dp[st][end] = ((s[st] == s[end]) && solve(st + 1, end - 1, s, dp));
    }
    
    int func(int i, int j, string &s, vector<vector<int>> &dp, vector<int> &dp1) {
        if (i >= j || dp[i][j]) return 0;
        if (dp1[i] != -1) return dp1[i];
        int res = INT_MAX;
        for (int k = i; k <= j; k++) {
            if (dp[i][k]) {
                res = min(res, 1 + func(k + 1, j, s, dp, dp1));
            }
        }
        return dp1[i] = res;
    }
    
    int palindromicPartition(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[j][i] = solve(j, i, s, dp);
            }
        }
        vector<int> dp1(n, -1);
        int ans = func(0, n - 1, s, dp, dp1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends