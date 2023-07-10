//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        // code here
        int ans = 0, mod = 1e9 + 7, a = 0, b = 1, c = 1;
        if(n == 1 || n == 2) return 1;
        while(n - 2 > 0) {
            a = b % mod;
            b = c % mod;
            c = (a + b) % mod;
            n--;
        } 
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends