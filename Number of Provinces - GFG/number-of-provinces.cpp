//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int i, vector<int> graph[], vector<int> &vis){
        vis[i]=1;
        for(auto it:graph[i]){
            if(!vis[it])
                solve(it,graph,vis);
        }
        return ;
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<int>graph[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(adj[i][j]){
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }
        vector<int>vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,graph,vis);
                c++;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends