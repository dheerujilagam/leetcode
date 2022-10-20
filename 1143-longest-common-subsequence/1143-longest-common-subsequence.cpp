class Solution {
public:
    int lcs(string &s1,string &s2, int m, int n, vector<vector<int>>&dp){
        if(m==0 || n==0)
            return dp[m][n]=0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s1[m-1]==s2[n-1])
            return dp[m][n]=1+lcs(s1,s2,m-1,n-1,dp);
        else
            return dp[m][n]=max(lcs(s1,s2,m-1,n,dp),lcs(s1,s2,m,n-1,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int ans=0,m=t1.size(),n=t2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return lcs(t1,t2,m,n,dp);
    }
};