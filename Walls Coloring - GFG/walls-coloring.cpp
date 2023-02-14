//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int pos, int prev, vector<vector<int>> &dp, vector<vector<int>> &colors){
        if(pos<0)
            return 0;
        if(dp[pos][prev]!=1e9)
            return dp[pos][prev];
        int cost=1e9;
        for(int i=0;i<=2;i++){
            if(i!=prev){
                cost=min(cost,colors[pos][i]+solve(pos-1,i,dp,colors));
            }
        }
        return dp[pos][prev]=cost;
    }
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        vector<vector<int>>dp(n,vector<int>(4,1e9));
        // for(int i=1;i<n;i++){
        //     colors[i][0]+=min(colors[i-1][1],colors[i-1][2]);
        //     colors[i][1]+=min(colors[i-1][0],colors[i-1][2]);
        //     colors[i][2]+=min(colors[i-1][1],colors[i-1][0]);
        // }
        // return min({colors[n-1][0],colors[n-1][1],colors[n-1][2]});
        return solve(n-1,3,dp,colors);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends