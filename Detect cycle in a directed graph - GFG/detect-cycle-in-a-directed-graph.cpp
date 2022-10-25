//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, int parent, vector<int>&vis1, vector<int>&vis2, vector<int>adj[]){
    	vis1[node]=1;
    	vis2[node]=1;
    	for(auto it:adj[node]){
    		if(!vis1[it]){
    			if(dfs(it,node,vis1,vis2,adj))
    				return true;
    		}
    		else if(vis2[it])
    			return true;
    	}
    	vis2[node]=0;
    	return false;
    }
    bool isCyclic(int n, vector<int>adj[]){
    	vector<int>vis1(n,0);
    	vector<int>vis2(n,0);
    	for(int i=0;i<n;i++){
    		if(!vis1[i]){
    			if(dfs(i,-1,vis1,vis2,adj))
    				return true;
    		}
    	}
    	return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends