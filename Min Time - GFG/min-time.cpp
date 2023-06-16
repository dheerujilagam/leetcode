//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    map<int, set<int>> mp;
    long long solve(int pos, int index, vector<int> &temp, vector<vector<long long>> &dp, int indication) {
        if(index == temp.size()) return 0;
        if(dp[index][indication] != -1) return dp[index][indication];
        int left = *mp[temp[index]].begin();
        int right = *mp[temp[index]].rbegin();
        long long one = abs(pos - left) + abs(left - right) + solve(right, index + 1, temp, dp, 0);
        if(index == mp.size() - 1) one += abs(right - 0);
        long long two = abs(pos - right) + abs(left - right) + solve(left, index + 1, temp, dp, 1);
        if(index == mp.size() - 1) two += abs(left - 0);
        return dp[index][indication] = min(one, two);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        for(int i = 0; i < n; i++) mp[types[i]].insert(locations[i]);
        vector<int> temp;
        for(auto it : mp) temp.push_back(it.first);
        vector<vector<long long>> dp(mp.size(), vector<long long> (2, -1));
        return solve(0, 0, temp, dp, 1);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends