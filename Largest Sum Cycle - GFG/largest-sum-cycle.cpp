//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
    
    void dfsT(int node, vector<int> adjT[], vector<int> &vis, int &c, int &sum){
        vis[node]=1;
        c++;
        sum+=node;
        for(int it:adjT[node]){
            if(!vis[it]){
                dfsT(it,adjT,vis,c,sum);
            }
        }
    }
    
    public:
    long long largestSumCycle(int n, vector<int> edge){
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edge[i]!=-1){
              adj[i].push_back(edge[i]);
           }
        }
      
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
        
        int ans=-1;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                int c=0,sum=0;
                dfsT(node,adjT,vis,c,sum);
                if(c>1)
                    ans=max(ans,sum);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends