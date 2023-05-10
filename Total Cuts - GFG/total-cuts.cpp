//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
         vector<int> pre(n), suf(n);
         int mx = -1, mn = 1e6 + 1, count = 0;
         for(int i = 0; i < n; i++) {
             mx = max(mx, a[i]);
             pre[i] = mx;
         } 
         for(int i = n - 1; i >= 0; i--) {
             mn = min(mn, a[i]);
             suf[i] = mn;
         }
         for(int i = 0; i < n - 1; i++) {
             if(pre[i] + suf[i + 1] >= k) count++;
         }
         return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends