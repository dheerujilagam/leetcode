//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        // code here
        int l=INT_MIN,r=0;
        for(int i=0;i<n;i++){
            if(l<arr[i]) l=arr[i];
            r+=arr[i];
        }
        while(l<r){
            int mid=(l+r)/2;
            int cur=0,c=1;
            for(int i=0;i<n;i++){
                cur+=arr[i];
                if(cur>mid){
                    c++;
                    cur=arr[i];
                }
            }
            if(c>k) l=mid+1;
            else r=mid;
        }
        return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends