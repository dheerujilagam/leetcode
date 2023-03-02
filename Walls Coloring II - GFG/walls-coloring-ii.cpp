//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int solve(int pos, int prev, vector<vector<int>> &dp, vector<vector<int>> &costs){
        if (pos < 0) return 0;
        if (dp[pos][prev] != -1) return dp[pos][prev];
        int cost = 1e9+1;
        for (int i = 0; i <= costs[0].size() - 1; i++) {
            if(i != prev) cost = min(cost, costs[pos][i] + solve(pos-1,i,dp,costs));
        }
        return dp[pos][prev] = cost;
    }
    
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        int k = costs[0].size();
        if (k == 1 && n == 1) return costs[0][0];
        if (k == 1 && n >= 2) return -1;
        
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        int minF = 1e9, minS = 1e9;
        
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
            if (minF > dp[0][i]) minS = minF, minF = dp[0][i];
            else if(minS > dp[0][i]) minS = dp[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            int tF = 1e9, tS = 1e9;
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] == minF) dp[i][j] = costs[i][j] + minS;
                else dp[i][j] = costs[i][j] + minF;
                if (tF > dp[i][j]) tS = tF, tF = dp[i][j];
                else if(tS > dp[i][j]) tS = dp[i][j];
            }
            minF = tF, minS = tS;
        }
        return minF;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends