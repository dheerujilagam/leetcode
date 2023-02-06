class Solution {
public:
    void dfs(int i, int j, int n, vector<vector<int>> &mat){
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==1)
            return ;
        mat[i][j]=1;
        dfs(i-1,j,n,mat);        
        dfs(i+1,j,n,mat);
        dfs(i,j-1,n,mat);
        dfs(i,j+1,n,mat);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>mat(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    mat[3*i][3*j+2]=1;
                    mat[3*i+1][3*j+1]=1;
                    mat[3*i+2][3*j]=1;
                }
                else if(grid[i][j]=='\\'){
                    mat[3*i][3*j]=1;
                    mat[3*i+1][3*j+1]=1;
                    mat[3*i+2][3*j+2]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(mat[i][j]==0){
                    c++;
                    dfs(i,j,3*n,mat);
                }
            }
        }
        return c;
        
    }
};