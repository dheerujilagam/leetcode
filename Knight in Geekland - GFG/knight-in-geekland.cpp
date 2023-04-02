//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>>moves{{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
    int knightInGeekland(int start_x, int start_y, vector<vector<int>> &arr){
        int n = arr.size(), m = arr[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_map<int, int> steps;
        q.push({start_x, start_y});
        vis[start_x][start_y] = 1;
        int count = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                pair<int, int> p = q.front();
    	        steps[count] += arr[p.first][p.second];
                q.pop();
                for(int k = 0; k < 8; k++){
    	            int x = p.first + moves[k][0], y = p.second + moves[k][1];
    	            if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y])
    	                continue;
    	            vis[x][y]=1;
    	            q.push({x, y});;
    	        }
            }
            count++;
        }
        int ans = -1, curMax = -1;
        for(int i = steps.size() - 1; i >= 0; i--) {
            if(i + steps[i] < steps.size()) steps[i] += steps[i + steps[i]];
            if(curMax <= steps[i]) {
                ans = i;
                curMax = steps[i];
            }
        }
        return ans;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends