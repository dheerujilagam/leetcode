class Solution {
public:
    void fill(vector<vector<int>>&image, int i, int j, int r, int c, int val, int color){
        if(i<0 || j<0 || i>=r || j>=c || image[i][j]!=val)
            return ;
        image[i][j]=color;
        fill(image,i+1,j,r,c,val,color);        
        fill(image,i-1,j,r,c,val,color);
        fill(image,i,j+1,r,c,val,color);
        fill(image,i,j-1,r,c,val,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int val=image[sr][sc];
        int r=image.size(),c=image[0].size();
        fill(image,sr,sc,r,c,val,color);
        return image;
    }
};