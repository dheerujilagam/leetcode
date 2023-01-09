//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        dp[0][0]=grid[0][0];
        while(!q.empty()){
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            int px=p.second.first,py=p.second.second;
            vector<pair<int,int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
            for(int i=0;i<4;i++){
                int x=px+moves[i].first,y=py+moves[i].second;
                if(x>=0 && y>=0 && x<n && y<n){
                    if(dp[x][y]>dp[px][py]+grid[x][y]){
                        dp[x][y]=dp[px][py]+grid[x][y];
                        q.push({dp[x][y],{x,y}});
                    }
                }
            }
        }
        return dp[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends