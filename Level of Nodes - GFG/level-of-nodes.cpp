//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<pair<int,int>>q;
	    vector<int>vis(v,0);
	    vis[0]=1;
	    q.push({0,0});
	    while(!q.empty()){
	        pair<int,int>p=q.front();
	        q.pop();
	        if(p.first==x)
	            return p.second;
	        for(auto i:adj[p.first]){
	            if(!vis[i]){
	                vis[i]=1;
	                q.push({i,p.second+1});
	            }
	        }
	    }
	    return -1;
	}
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends