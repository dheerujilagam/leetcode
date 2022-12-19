//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>>adj[n+1];
        vector<int>dis(n+1,INT_MAX);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty()){
            int u=pq.top().first,v=pq.top().second;
            pq.pop();
            for(auto it:adj[v]){
                if(dis[v]+it.second<=dis[it.first]){
                    dis[it.first]=dis[v]+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,dis[i]);
        }
        return mx==INT_MAX?-1:mx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends