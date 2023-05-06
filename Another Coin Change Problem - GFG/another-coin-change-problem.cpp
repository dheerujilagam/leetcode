//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool solve(int id, int n, int k, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if(k == 0) return target == 0;
        if(id >= n) return false;
        if(dp[k][target] != -1) return dp[k][target];
        if(target - coins[id] >= 0) return dp[k][target] = (solve(id, n, k - 1, target - coins[id], coins, dp) || solve(id + 1, n, k, target, coins, dp));
        else return dp[k][target] = solve(id + 1, n, k, target, coins, dp);
    }
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        // code here
        vector<vector<int>> dp(k + 1, vector<int> (target + 1, -1));
        return solve(0, n, k, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends