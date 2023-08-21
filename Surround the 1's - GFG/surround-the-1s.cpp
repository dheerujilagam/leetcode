//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool helper(vector<vector<int>>&matrix,int i,int j){
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                int r=i+k;
                int c=j+l;
                if(r>=0 and c>=0 and r<n and c<m){
                    if(matrix[r][c]==0)
                    count++;
                }
            }
        }
        if(count==0)return false;
        return !(count&1);
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    if(helper(matrix,i,j))c++;
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends