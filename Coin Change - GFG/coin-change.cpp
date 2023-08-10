//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int ind, int coins[], int n, int sum, vector<vector<long long int>> &dp) {
        if(sum == 0) return 1;
        if(ind == n || sum < 0) return 0;
        if(dp[sum][ind] != -1) return dp[sum][ind];
        return dp[sum][ind] = solve(ind, coins, n, sum - coins[ind], dp) + solve(ind + 1, coins, n, sum, dp);
    }
    long long int count(int coins[], int n, int sum) {
        // code here.
        vector<vector<long long int>> dp(sum + 1, vector<long long int> (n, -1));
        return solve(0, coins, n, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends