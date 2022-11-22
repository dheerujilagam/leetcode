//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int c=0,n=nums.size();
	    for(int i=1;i<n-1;i++){
	        int l=0;
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                l++;
	        }
	        int r=0;
	        for(int k=i+1;k<n;k++){
	            if(nums[i]<nums[k])
	                r++;
	        }
	        c+=(l*r);
	    }
	    return c;
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
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends