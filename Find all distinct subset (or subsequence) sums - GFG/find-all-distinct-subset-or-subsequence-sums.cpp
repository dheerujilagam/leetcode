//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
	    sort(nums.begin(), nums.end());
	    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
	    for(int i = 0; i <= n; i++) dp[i][0] = 1;
	    for(int i = 1; i <= n; i++) {
	        for(int j = 1; j <= sum; j++) {
	            if(j - nums[i - 1] >= 0) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
	            else dp[i][j] = dp[i - 1][j];
	        }
	    }
	    vector<int> ans;
	    for(int j = 0; j <= sum; j++) {
	        if(dp[n][j]) ans.push_back(j);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends