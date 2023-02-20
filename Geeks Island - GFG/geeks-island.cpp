//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int n,m;
    vector<vector<bool>>p,a;
    vector<vector<int>>ans;
    int cnt;
    vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i, int j, vector<vector<int>> &h, vector<vector<bool>> &v){
        v[i][j]=true;
        if(p[i][j] && a[i][j]) 
            cnt++;
            //ans.push_back({i,j});
        for(auto it:moves){
            int x=i+it[0],y=j+it[1];
            if(x<0 || y<0 || x>=n || y>=m || v[x][y] || h[i][j]>h[x][y])
                continue;
            dfs(x,y,h,v);
        }
    }
    
    
    int water_flow(vector<vector<int>> &hts,int x,int y){
        n=x;
        m=y;
        cnt=0;
        p=vector<vector<bool>>(n,vector<bool>(m,false));
        a=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(!p[i][0])
                dfs(i,0,hts,p);
            if(!a[i][m-1])
                dfs(i,m-1,hts,a);
        }
        for(int i=0;i<m;i++){
            if(!p[0][i])
                dfs(0,i,hts,p);
            if(!a[n-1][i])
                dfs(n-1,i,hts,a);
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends