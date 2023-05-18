//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &mat) {
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == 0) return ;
        mat[i][j] = 0;
        dfs(i - 1, j, n, m, mat);
        dfs(i + 1, j, n, m, mat);
        dfs(i, j - 1, n, m, mat);
        dfs(i, j + 1, n, m, mat);
        return ;
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        int no_of_islands = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    dfs(i, j, n, m, mat);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    no_of_islands++;
                    dfs(i, j, n, m, mat);
                }
            }
        }
        return no_of_islands;
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