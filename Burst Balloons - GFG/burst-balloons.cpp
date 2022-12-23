//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &arr){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mx=-1;
        for(int k=i;k<=j;k++){
            int ans=arr[i-1]*arr[k]*arr[j+1]+solve(i,k-1,dp,arr)+solve(k+1,j,dp,arr);
            mx=max(ans,mx);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(int n, vector<int> &arr) {
        // code here
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        return solve(1,n,dp,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends