class Solution {
public:
    bool issafe(int r, int c, vector<vector<char>>&board, char val){
        for(int i=0;i<9;i++){
            if(board[r][i]==val)
                return false;
            if(board[i][c]==val)
                return false;
            if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==val)
                return false;
        }
        return true;
    }
    bool check(vector<vector<char>>&board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(isdigit(board[r][c])){
                    char val=board[r][c];
                    board[r][c]='.';
                    if(!issafe(r,c,board,val))
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board);
    }
};