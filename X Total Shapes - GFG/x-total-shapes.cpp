//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    vector<vector<int>>moves{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='X')
            return ;
        grid[i][j]='O';
        for(int k=0;k<4;k++){
            int x=i+moves[k][0],y=j+moves[k][1];
            dfs(x,y,n,m,grid);
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n=grid.size(),m=grid[0].size(),c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    c++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends