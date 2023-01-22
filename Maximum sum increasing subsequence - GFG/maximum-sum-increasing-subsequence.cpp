//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int a[], int n)  
	{  
	    int mxs=0;
	    vector<int>dp(n,0);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i] && dp[i]<a[j]+dp[j]){
	                dp[i]=a[j]+dp[j];
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        dp[i]+=a[i];
	        mxs=max(mxs,dp[i]);
	    }
	    return mxs;
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