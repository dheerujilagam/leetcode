class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i+1)<m and j+1<n){
                    if(mat[i][j]!=mat[i+1][j+1])
                        return false;
                }
            }
        }
        return true;
    }
};