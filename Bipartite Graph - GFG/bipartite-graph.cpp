//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool graphColor(int i, vector<int> adj[], vector<int> &colors){
        queue<int>q;
        q.push(i);
        colors[i]=1;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto it:adj[cur]){
                if(colors[it]==-1){
                    q.push(it);
                    colors[it]=1-colors[cur];
                }
                else if(colors[it]==colors[cur])
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>colors(V,-1);
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
                if(!graphColor(i,adj,colors))
                    return false;
            }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends