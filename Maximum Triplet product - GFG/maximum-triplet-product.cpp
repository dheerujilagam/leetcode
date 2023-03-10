//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	long long minF = LLONG_MAX, minS = LLONG_MAX, maxF = LLONG_MIN, maxS = LLONG_MIN, maxT = LLONG_MIN;
    	for(int i = 0; i < n; i++) {
    	    if(minF > arr[i]) {
    	        minS = minF;
    	        minF = arr[i];
    	    }
    	    else if(minS > arr[i]) {
    	        minS = arr[i];
    	    }
    	    if(maxF < arr[i]) {
    	        maxT = maxS;
    	        maxS = maxF;
    	        maxF = arr[i];
    	    }
    	    else if(maxS < arr[i]) {
    	        maxT = maxS;
    	        maxS = arr[i];
    	    }
    	    else if(maxT < arr[i]) {
    	        maxT = arr[i];
    	    }
    	}
    // 	cout << minF << " " << minS << " " << maxF << " " << maxS << " " << maxT << " ";
    	return max(minF * minS * maxF, maxF * maxS * maxT);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends