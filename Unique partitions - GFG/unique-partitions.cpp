//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int id, int n, vector<int>&arr, int sum, vector<vector<int>>&res, vector<int>t){
	    if(sum<0)
	        return ;
	    if(sum==0){
	        res.push_back(t);
	        return ;
	    }
	    for(int i=id;i<n;i++){
	        t.push_back(arr[i]);
            sum-=arr[i];
            solve(i,n,arr,sum,res,t);
            sum+=arr[i];
            t.pop_back();
	    }
	    return ;
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>>res;
        vector<int>t;
        vector<int>arr;
        for(int i=n;i>=1;i--){
            arr.push_back(i);
        }
        solve(0,n,arr,n,res,t);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends