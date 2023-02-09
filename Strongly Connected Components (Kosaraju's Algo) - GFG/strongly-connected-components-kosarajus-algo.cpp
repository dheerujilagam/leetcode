//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void dfsT(int node, vector<int> adjT[], vector<int> &vis){
        vis[node]=1;
        for(int it:adjT[node]){
            if(!vis[it]){
                dfsT(it,adjT,vis);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        //code here
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>adjT[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(int it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int connected=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                vis[node]=1;
                connected++;
                for(int it:adjT[node]){
                    if(!vis[it]){
                        dfsT(it,adjT,vis);
                    }
                }
            }
        }
        
        return connected;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends