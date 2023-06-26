//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MOD = 1e9 + 7;
    long long int binexp(long long int a, long long int b) {
    	if(b == 0) return 1;
    	long long int res = binexp(a, b / 2) % MOD;
    	if(b & 1) return res * res % MOD * a % MOD;
    	else return res * res % MOD;
    }
    int nCr(int n, int r){
        // code here
        if(r > n) return 0;
        long long int x = 1, y = 1, z = 1;
        for(int i = 2; i <= n; i++) x = (x * i) % MOD;
        for(int i = 2; i <= (n - r); i++) y = (y * i) % MOD;
        for(int i = 2; i <= r; i++) z = (z * i) % MOD;
        // cout << x << " " << y << " " << z << endl;
        y = binexp(y, MOD - 2);
        z = binexp(z, MOD - 2);
        // cout << x << " " << y << " " << z << endl;
        return ((x * y) % MOD * z) % MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends