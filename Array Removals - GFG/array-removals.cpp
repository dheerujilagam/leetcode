//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int n=arr.size(),mx=0;
        int dp[n][n]={0};
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(arr[j]-arr[i])<=k){
                    if(j>0)
                        dp[i][j]=dp[i][j-1]+1;
                    else
                        dp[i][j]+=1;
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        return n-mx;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends