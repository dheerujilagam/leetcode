//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int solve(string &s, string &p, int l1, int l2, vector<vector<int>> &dp){
        if(l1<0 && l2<0){
            return 1;
        }
        if(l1>=0 && l2<0)
            return 0;
        if(l1<0 && l2>=0){
            for(int i=0;i<=l2;i++){
                if(p[i]!='*')
                    return 0;
            }
            return 1;
        }
        if(dp[l1+1][l2+1]!=-1)
            return dp[l1+1][l2+1];
        int ans=0;
        if(p[l2]=='?'){
            if(solve(s,p,l1-1,l2-1,dp))
                ans=1;
        }
        else if(p[l2]=='*'){
            if(solve(s,p,l1-1,l2-1,dp))
                ans=1;
            if(solve(s,p,l1,l2-1,dp))
                ans=1;
            if(solve(s,p,l1-1,l2,dp))
                ans=1;
        }
        else if(s[l1]==p[l2])
            if(solve(s,p,l1-1,l2-1,dp))
                ans=1;
        return dp[l1+1][l2+1]=ans;
    }
    int wildCard(string p,string s)
    {
        int l1=s.size(),l2=p.size();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return solve(s,p,l1-1,l2-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends