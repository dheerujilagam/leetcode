//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void dfsT(int node, vector<int> adjT[], vector<int> &vis, vector<int> &v){
        vis[node]=1;
        v.push_back(node);
        for(int it:adjT[node]){
            if(!vis[it]){
                dfsT(it,adjT,vis,v);
            }
        }
    }
    vector<vector<int>> tarjans(int n, vector<int> adj[])
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
        
        //int connected=0;
        vector<vector<int>>res;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                //connected++;
                vector<int>t;
                dfsT(node,adjT,vis,t);
                sort(t.begin(),t.end());
                res.push_back(t);
            }
        }
        sort(res.begin(),res.end());
        return res;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends