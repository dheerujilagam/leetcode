//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool check(int i, int j, int m, int n,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
            return false;
        return true;
    }
    void islands(int i, int j, int m, int n, vector<vector<char>>& grid){
        grid[i][j]='0';
        if(check(i-1,j,m,n,grid))
            islands(i-1,j,m,n,grid);
        if(check(i+1,j,m,n,grid))
            islands(i+1,j,m,n,grid);
        if(check(i,j-1,m,n,grid))
            islands(i,j-1,m,n,grid);
        if(check(i,j+1,m,n,grid))
            islands(i,j+1,m,n,grid);
        if(check(i-1,j-1,m,n,grid))
            islands(i-1,j-1,m,n,grid);
        if(check(i+1,j+1,m,n,grid))
            islands(i+1,j+1,m,n,grid);
        if(check(i+1,j-1,m,n,grid))
            islands(i+1,j-1,m,n,grid);
        if(check(i-1,j+1,m,n,grid))
            islands(i-1,j+1,m,n,grid);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int c=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    c++;
                    islands(i,j,m,n,grid);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends