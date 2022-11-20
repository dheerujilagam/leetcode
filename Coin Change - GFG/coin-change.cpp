//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long change(int coins[], vector<vector<long long>>&dp, int n, int target, int sum, int id){
        if(sum==target)
            return 1;
        if(id>=n || sum>target)
            return 0;
        if(dp[id][sum]!=-1)
            return dp[id][sum];
        long long ans=0;
        for(int i=id;i<n;i++)
            ans+=change(coins,dp,n,target,sum+coins[i],i);
        return dp[id][sum]=ans;
    }
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long>>dp(n+1,vector<long long>(sum+1,-1));
        sort(coins,coins+n);
        return change(coins,dp,n,sum,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends