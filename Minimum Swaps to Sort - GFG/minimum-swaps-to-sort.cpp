//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int> &nums)
	{
	    // Code here
	    int swaps = 0, n = nums.size();
	    vector<int> vp(n), vis(n, 0);
	    for (int i = 0; i < n; i++) vp[i] = nums[i];
	    sort(vp.begin(), vp.end());
	    unordered_map<int,int> mp;
	    for (int i = 0; i < n; i++) mp[vp[i]] = i;
	    for (int i = 0; i < n; i++) {
	        if (vp[i] != nums[i] && !vis[i]) {
	            queue<int> q;
	            q.push(mp[nums[i]]);
	            while (!q.empty()) {
	                int node = q.front();
	                q.pop();
	                vis[node] = 1;
	                if (!vis[mp[nums[node]]]) q.push(mp[nums[node]]), swaps++;
	            }
	        }
	    }
	    return swaps;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends