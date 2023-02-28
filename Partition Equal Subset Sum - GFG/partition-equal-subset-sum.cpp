//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int i, int n, int l, int r, int arr[], vector<vector<int>> &dp) {
        if(i == n){
            if(l == r)
                return 1;
            return 0;
        }
        if(dp[i][l] != -1)
            return dp[i][l];
        return dp[i][l] = (solve(i + 1, n, l + arr[i], r - arr[i], arr, dp) || solve(i + 1, n, l, r, arr, dp));
    }
    
    
    int equalPartition(int n, int arr[]) {
        // code here
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        vector<vector<int>> dp(n, vector<int> (sum, -1));
        return solve(0, n, 0, sum, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends