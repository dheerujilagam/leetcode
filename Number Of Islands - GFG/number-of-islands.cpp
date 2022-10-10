//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid, int cur){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==cur){
            return true;   
        }
        return false;
    }
    void check(vector<vector<int>>&grid, int r, int c, int n, int m, int cur){
        grid[r][c]+=1;
        if(isValid(r+1,c,n,m,grid,cur))
            check(grid,r+1,c,n,m,cur);
        if(isValid(r-1,c,n,m,grid,cur))
            check(grid,r-1,c,n,m,cur);
        if(isValid(r,c+1,n,m,grid,cur))
            check(grid,r,c+1,n,m,cur);
        if(isValid(r,c-1,n,m,grid,cur))
            check(grid,r,c-1,n,m,cur);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<int>ans;
        int cur=1;
        for(int i=0;i<op.size();i++){
            int ct=0;
            grid[op[i][0]][op[i][1]]=cur;
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    if(grid[r][c]==cur){
                        check(grid,r,c,n,m,cur);
                        ct++;
                    }
                }
            }
            ans.push_back(ct);
            cur++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends