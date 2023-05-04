//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int solve(int id, int count, vector<vector<int>> &ranges, vector<vector<int>> &dp) {
        if(count == 0 || id == ranges.size()) return 0;
        if(dp[id][count] != -1) return dp[id][count];
        int inc = ranges[id][2];
        int lo = id + 1, hi = ranges.size() - 1, idx = ranges.size();
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(ranges[mid][0] >= ranges[id][1]) idx = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        inc += solve(idx, count - 1, ranges, dp);
        int exc = solve(id + 1, count, ranges, dp);
        // cout << inc << " " << exc << " " << count << endl;
        return dp[id][count] = max(inc, exc);
    }
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return solve(0, 2, ranges, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends