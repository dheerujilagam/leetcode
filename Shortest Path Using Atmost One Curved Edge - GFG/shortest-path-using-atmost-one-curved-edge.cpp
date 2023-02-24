//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    vector<int> dij(int s, int n, vector<pair<int,int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dis(n + 1, 1e9);
        pq.push({0,s});
        dis[s] = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(auto v : adj[u]) {
                if(dis[u] + v.second < dis[v.first]) {
                    dis[v.first] = dis[u] + v.second;
                    pq.push({dis[v.first], v.first});
                }
            }
        }
        return dis;
    }
    
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> disA = dij(a, n, adj);
        vector<int> disB = dij(b, n, adj);
        
        int res = disA[b];
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], c = edges[i][3];
            res = min(res, min(disA[u] + c + disB[v], disA[v] + c + disB[u]));
        }
        if(res >= 1e9)
            return -1;
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends