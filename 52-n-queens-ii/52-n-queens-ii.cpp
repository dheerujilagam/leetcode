class Solution {
public:
    bool boundary(int i, int j, int n){
        if(i<0 or j<0 or i>=n or j>=n)
            return false;
        return true;
    }
    bool issafe(int row, int col, vector<string>t, int n){
        for(int i=0;i<n;i++){
            if(t[i][col]=='Q' or t[row][i]=='Q')
                return false;
        }
        for(int j=0;j<n;j++){
            if(boundary(row-j,col-j,n) and t[row-j][col-j]=='Q')
                return false;
            if(boundary(row+j,col-j,n) and t[row+j][col-j]=='Q')
                return false;
            if(boundary(row-j,col+j,n) and t[row-j][col+j]=='Q')
                return false;
            if(boundary(row+j,col+j,n) and t[row+j][col+j]=='Q')
                return false;
        }
        return true;
    }
    void rec(vector<vector<string>>&ans, vector<string>t, int n, int row){
        if(row==n){
            ans.push_back(t);
            return ;
        }
        for(int i=0;i<n;i++){
            if(issafe(row,i,t,n)){
                t[row][i]='Q';
                rec(ans,t,n,row+1);
                t[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        if(n==1){
            return 1;
        }
        if(n==2 || n==3){
            return 0;
        }
        string s(n,'.');
        vector<string>t(n,s);
        vector<vector<string>>ans;
        rec(ans,t,n,0);
        return ans.size();
    }
};