//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	struct node{
        int u,v,wt;
        node(int first , int second, int wight){
            u = first;
            v = second;
            wt = wight;
        }
        
    };
    
    static bool comp(node a , node b){
        return a.wt < b.wt;
    }
	
	int parent[1001];
	int rank[1001];
	void setData(){
	    for(int i=0;i<=1000;i++){
	        rank[i]=0;
	        parent[i]=i;
	    }
	}
	
	int findParent(int node){
	    if(parent[node]==node)
	        return node;
	    return parent[node]=findParent(parent[node]);
	}
	
	void Union(int u, int v){
	    u=findParent(u);
	    v=findParent(v);
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
	    else if(rank[u]>rank[v]){
	        parent[v]=u;
	    }
	    else{
	        parent[v]=u;
	        rank[u]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // 	int ans=0;
        // 	vector<int>vis(v,0);
        // 	pq.push({0,0});
        // 	while(!pq.empty()){
        // 	    pair<int,int>p=pq.top();
        // 	    pq.pop();
        // 	    int node=p.second;
        // 	    int wt=p.first;
        // 	    if(!vis[node]){
        // 	        vis[node]=1;
        // 	        ans+=wt;
        // 	        for(auto it:adj[node]){
        // 	            if(!vis[it[0]]){
        // 	                pq.push({it[1],it[0]});
        // 	            }
        // 	        }
        // 	    }
        // 	}
        // 	return ans;
        setData();
        vector<node>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i,v=it[0],wt=it[1];
                edges.push_back(node(u,v,wt));
            }
        }
        sort(edges.begin(),edges.end(),comp);
        int cost=0;
        for(auto it:edges){
            if(findParent(it.v)!=findParent(it.u)){
                cost+=it.wt;
                Union(it.v,it.u);
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends