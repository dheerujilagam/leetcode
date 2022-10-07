class Solution {
public:
    long long mod=1e9+7;
    int rec(int n, int k, int ct, int tar, vector<vector<int>>&dp){
        if(n==ct){
            if(tar==0)
                return 1;
            return 0;
        }
        if(dp[ct][tar]!=-1)
            return dp[ct][tar];
        long long tot=0;
        for(int i=1;i<=k;i++)
            if(tar>=i)
                tot+=rec(n,k,ct+1,tar-i,dp)%mod;
        return dp[ct][tar]=tot%mod;
    }
    int numRollsToTarget(int n, int k, int tar) {
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return rec(n,k,0,tar,dp)%mod;
    }
};