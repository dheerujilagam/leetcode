//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int size;
        int solve(int l, int r, vector<int> &a, vector<vector<int>> &dp) {
            if(l > r) return 0;
            if(dp[l][r] != -1) return dp[l][r];
            int val = INT_MIN;
            for(int i = l; i <= r; i++) {
                int p = 1, q = 1;
                if(l - 1 >= 0) p = a[l - 1];
                if(r + 1 < size) q = a[r + 1];
                val = max(val, solve(l, i - 1, a, dp) + solve(i + 1, r, a, dp) + (p * a[i] * q));
            }
            return dp[l][r] = val;
        }
        int maxCoins(int n, vector <int> &a) {
            size = n;
            vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
            return solve(0, n - 1, a, dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends