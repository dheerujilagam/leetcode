//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[100001][2];
    void dfs(int u, int prev, vector<int> adj[]){
        dp[u][1]=1;
        for(int v:adj[u]){
            if(v==prev)
                continue;
            dfs(v,u,adj);
            dp[u][1]+=min(dp[v][1],dp[v][0]);
            dp[u][0]+=dp[v][1];
        }
    }
    int countVertex(int n, vector<vector<int>>edges){
        vector<int>adj[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(1,0,adj);
        return min(dp[1][0],dp[1][1]);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends