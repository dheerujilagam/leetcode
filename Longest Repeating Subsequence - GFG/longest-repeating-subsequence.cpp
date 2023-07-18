//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int solve(int l, int r, string &s, vector<vector<int>> &dp) {
        if(l == s.length() || r == s.length()) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int cur = 0;
        if(s[l] == s[r] && l != r) cur = 1 + solve(l + 1, r + 1, s, dp);
        else cur = max(solve(l + 1, r, s, dp), solve(l, r + 1, s, dp));
        return dp[l][r] = cur;
    }
	int LongestRepeatingSubsequence(string s){
	    int n = s.length();
	    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
	    int ans = solve(0, 0, s, dp);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends