//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int i, int n, int sum, vector<int> &arr, vector<vector<int>> &dp){
	    if(sum < 0)
	        return 0;
	    if(i == n){
	        if(sum == 0)
	            return 1;
	        return 0;
	    }
	    if(dp[i][sum] != -1)
	        return dp[i][sum];
	    int in = solve(i + 1, n, sum - arr[i], arr, dp);
	    int ex = solve(i + 1, n, sum, arr, dp);
	    return dp[i][sum] = in | ex;
	}
	
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, n, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends