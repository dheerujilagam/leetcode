//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dfs(int st, int end, vector<pair<int, int>> adj[], vector<int> &dp) {
        if(st == end) return 0;
        if(dp[st] != -1) return dp[st];
        int ans = INT_MAX;
        for(auto it : adj[st]) {
            int cur = dfs(it.first, end, adj, dp);
            if(cur != INT_MAX) ans = min(ans, cur + it.second);
        }
        return dp[st] = ans;
    }
  
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[n];
        for(vector<int> it : edges) {
            int u = it[0], v = it[1], z = it[2];
            adj[u].push_back({v, z});
        }
        vector<int> res(n, 0);
        for(int i = 1; i < n; i++) {
            vector<int> dp(n, -1);
            int c = dfs(0, i, adj, dp);
            if(c == INT_MAX) res[i] = -1;
            else res[i] = c;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends