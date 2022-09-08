class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int i = mat.size()-1, j = 0;
        while ( i >= 0 && j < mat[0].size() ){
            if ( mat[i][j] == x )
                return true;
            if ( mat[i][j] > x )
                i--;
            else
                j++;
        }
        return false;
    }
};