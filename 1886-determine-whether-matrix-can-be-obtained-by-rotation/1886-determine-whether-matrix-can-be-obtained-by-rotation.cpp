class Solution {
public:
    void rotate(vector<vector<int>>&a, int n){
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int t=a[i][j];
                a[i][j]=a[n-j-1][i];
                a[n-j-1][i]=a[n-i-1][n-j-1];
                a[n-i-1][n-j-1]=a[j][n-i-1];
                a[j][n-i-1]=t;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
            return true;
        for(int k=1;k<4;k++){
            rotate(mat,mat.size());
            if(mat==target)
                return true;
        }
        return false;
    }
};