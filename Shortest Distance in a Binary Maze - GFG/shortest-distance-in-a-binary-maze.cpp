//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>>moves{{1,0},{0,1},{-1,0},{0,-1}};
    int shortestPath(vector<vector<int>> &grid, pair<int,int>st, pair<int,int>d){
        int stx=st.first,sty=st.second;
        int endx=d.first,endy=d.second;
        if(grid[stx][sty]==0 && stx!=endx && sty!=endy)
            return -1;
        int n=grid.size(),m=grid[0].size();
        //vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        q.push({0,stx,sty});
        grid[stx][sty]=0;
        //vis[stx][sty]=1;
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
            int count=v[0];
            int i=v[1];
            int j=v[2];
            if(i==endx && j==endy)
                return count;
            for(auto it:moves){
                int x=i+it[0],y=j+it[1];
                if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)
                    continue;
                grid[x][y]=0;
                q.push({count+1,x,y});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends