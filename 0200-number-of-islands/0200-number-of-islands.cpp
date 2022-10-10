class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1'){
            return true;   
        }
        return false;
    }
    void check(vector<vector<char>>& grid, int i, int j, int n, int m){
        grid[i][j] = 0;
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
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    check(grid,i,j,n,m);
                }
            }
        }
        return c;
    }
};