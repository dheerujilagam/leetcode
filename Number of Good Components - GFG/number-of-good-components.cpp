//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &tem){
        vis[node] = 1;
        tem.push_back(node);
        for(int it : adj[node]){
            if(!vis[it])
                dfs(it, adj, vis, tem);
        }
    }
    
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        int cnt = 0;
        vector<int> vis(V + 1, 0);
        for(int i = 1; i <= V; i++){
            if(!vis[i]){
                vector<int> tem;
                dfs(i, adj, vis, tem);
                int len = tem.size(), flag = 1;
                if(len - 1 == adj[i].size()){
                    for(int it : tem){
                        if(adj[it].size() != len - 1){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends