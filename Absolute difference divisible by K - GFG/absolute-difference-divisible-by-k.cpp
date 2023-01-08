//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        long dp[k]={0};
        for(int i=0;i<n;i++){
            arr[i]=(arr[i]+k)%k;
        }
        for(int i=0;i<n;i++)
            dp[arr[i]%k]++;
        long c=0;
        for(int i=0;i<k;i++){
            if(dp[i]!=0)
                c+=(dp[i]*(dp[i]-1)/2);
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends