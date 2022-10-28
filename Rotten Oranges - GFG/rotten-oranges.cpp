//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),fresh=0,time=-1;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i>0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(j>0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    fresh--;
                }
                if(i<m-1 and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(j<n-1 and grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    fresh--;
                }
            }
            time++;
        }
        if(fresh!=0)
            return -1;
        else if(time==-1)
            return 0;
        else
            return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends