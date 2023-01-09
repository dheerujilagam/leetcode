//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;   
        }
        return false;
    }
    void check(vector<vector<int>>& grid, int i, int j, int n, int m){
        grid[i][j]=0;
        if(isValid(i+1, j, n, m, grid)){
            check(grid, i+1, j, n, m);
        }
        if(isValid(i-1, j, n, m, grid)){
            check(grid, i-1, j, n, m);
        }
        if(isValid(i, j+1, n, m, grid)){
            check(grid, i, j+1, n, m);
        }
        if(isValid(i, j-1, n, m, grid)){
            check(grid, i, j-1, n, m);
        }
    }
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        // Code here
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                    check(grid,i,j,n,m);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c++;
                    check(grid,i,j,n,m);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends