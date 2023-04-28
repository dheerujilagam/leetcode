//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> res(n, vector<int> (m, -1));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, pair<int,int>>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'W') {
                    vis[i][j] = 1;
                    res[i][j] = 0;
                    q.push({0, {i, j}});
                }
                if(c[i][j] == 'N') vis[i][j] = 1, res[i][j] = 0;
                if(c[i][j] == '.') res[i][j] = 0;
            }
        }
        vector<pair<int, int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto v = q.front();
            q.pop();
            for(auto it : moves) {
                int x = it.first + v.second.first, y = it.second + v.second.second;
                if(x < n && y < m && x >= 0 && y >= 0 && !vis[x][y] && (c[x][y] == 'H' || c[x][y] == '.')) {
                    if(c[x][y] == 'H') res[x][y] = (v.first + 1) * 2;
                    vis[x][y] = 1;
                    q.push({v.first + 1, {x, y}});
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends