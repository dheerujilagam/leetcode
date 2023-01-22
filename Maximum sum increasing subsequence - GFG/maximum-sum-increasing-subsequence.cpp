//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[1001][1001];
	int solve(int i, int pre, int n, int arr[]){
	    if(i==n)
	        return 0;
	    if(dp[i][pre+1]!=-1)
	        return dp[i][pre+1];
	    int a=0,b=0;
	    if(pre==-1 || arr[pre]<arr[i]){
	        a=arr[i]+solve(i+1,i,n,arr);
	        b=solve(i+1,pre,n,arr);
	        return dp[i][pre+1]=max(a,b);
	    }
	    else{
	        return dp[i][pre+1]=solve(i+1,pre,n,arr);
	    }
	}
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp,-1,sizeof(dp));
	    return solve(0,-1,n,arr);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends