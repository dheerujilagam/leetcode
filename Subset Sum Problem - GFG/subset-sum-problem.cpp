//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int id, int sum, vector<int> &arr, vector<vector<int>> &dp) {
        if(sum == 0) return 1;
        if(id == arr.size()) return 0;
        if(dp[id][sum] != -1) return dp[id][sum];
        int a = 0, b = 0;
        if(sum - arr[id] >= 0) a = solve(id + 1, sum - arr[id], arr, dp);
        b = solve(id + 1, sum, arr, dp);
        return dp[id][sum] = a | b;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return solve(0, sum, arr, dp);
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