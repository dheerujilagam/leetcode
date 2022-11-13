//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> arr, int r, int c) {
        // code here
        if(r==0 and c==0)
            return 0;
        if(arr[0][0]==0)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(i==r and j==c){
                return arr[i][j]-1;
            }
            if(i>=1 and arr[i-1][j]==1){
                q.push({i-1,j});
                arr[i-1][j]=arr[i][j]+1;
            }
            if(i<n-1 and arr[i+1][j]==1){
                q.push({i+1,j});
                arr[i+1][j]=arr[i][j]+1;
            }
            if(j>=1 and arr[i][j-1]==1){
                q.push({i,j-1});
                arr[i][j-1]=arr[i][j]+1;
            }
            if(j<m-1 and arr[i][j+1]==1){
                q.push({i,j+1});
                arr[i][j+1]=arr[i][j]+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends