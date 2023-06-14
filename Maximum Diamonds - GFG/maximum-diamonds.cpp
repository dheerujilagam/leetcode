//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        // code here
        priority_queue<int> pq;
        int t = 0;
        for(int i = 0; i < n; i++) pq.push(a[i]);
        long long ans = 0;
        while(k--) {
            t = pq.top();
            ans += t;
            pq.pop();
            t /= 2;
            pq.push(t);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends