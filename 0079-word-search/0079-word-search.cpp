class Solution {
public:
    bool dfs(int i, int j, int n, int m, vector<vector<char>>& board, string word, int k){
        if(k==word.size())
            return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[k])
            return false;
        char tem=board[i][j];
        board[i][j]='#';
        if(dfs(i+1,j,n,m,board,word,k+1) || dfs(i-1,j,n,m,board,word,k+1) || dfs(i,j+1,n,m,board,word,k+1) || dfs(i,j-1,n,m,board,word,k+1))
            return true;
        board[i][j]=tem;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and dfs(i,j,n,m,board,word,0)){
                        return true;
                }
            }
        }
        return false;
    }
};