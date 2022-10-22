//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int n) {
        // code here
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int arr[n+1];
        arr[1]=1;
        arr[2]=2;
        for(int i=3;i<=n;i++)
            arr[i]=(arr[i-1]+arr[i-2])%100000000;
        return arr[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends