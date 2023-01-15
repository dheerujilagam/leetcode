//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(long v,long n,long m,long l,long h[],long a[]){
        long tot=0;
        for(long i=0;i<n;i++){
            long cur=h[i]+(a[i]*v);
            if(cur>=l)
            tot+=cur;
        }
        if(tot>=m){
            return 1;
        }
        return 0;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long low=0,high=10e9+7;
        long ans;
        while(low<=high){
            long mid=(low+high)/2;
            if(check(mid,N,M,L,H,A)){
                high=mid-1;
                ans=mid;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends