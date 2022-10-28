//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
        // Code here 
        if(image[sr][sc]==color)
            return image;
        int val=image[sr][sc];
        int r=image.size(),c=image[0].size();
        fill(image,sr,sc,r,c,val,color);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends