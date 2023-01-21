//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt = 0, x = 1, res = 0;
        while(b) {
            b = b & (b - 1);
            cnt++;
        }
        while((x << 1) <= a) x <<= 1;
        while(cnt > 0 && x > 0) {
            if(x & a) {
                res |= x;
                cnt--;
            }
            x >>= 1;
        }
        x = 1;
        while(cnt > 0) {
            if((x & res) == 0) {
                res |= x;
                cnt--;
            }
            x <<= 1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends