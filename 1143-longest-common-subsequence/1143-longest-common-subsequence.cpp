class Solution {
public:
    // int lcs(string &s1,string &s2, int m, int n, vector<vector<int>>&dp){
    //     if(m==0 || n==0)
    //         return dp[m][n]=0;
    //     if(dp[m][n]!=-1)
    //         return dp[m][n];
    //     if(s1[m-1]==s2[n-1])
    //         return dp[m][n]=1+lcs(s1,s2,m-1,n-1,dp);
    //     else
    //         return dp[m][n]=max(lcs(s1,s2,m-1,n,dp),lcs(s1,s2,m,n-1,dp));
    // }
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size(),n=t2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return lcs(t1,t2,m,n,dp);
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t1[i-1]==t2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};