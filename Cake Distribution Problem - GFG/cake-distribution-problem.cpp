//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool binarysearch(vector<int> &s, int m, int k) {
        int sum = 0;
        for(int it : s) {
            sum += it;
            if(sum >= m) {
                k--;
                sum = 0;
            }
        }
        return k <= -1;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
        int l = 1e9, h = 0;
        for(int it : s) h += it, l = min(l, it);
        int m;
        while(l <= h) {
            m = (h + l) / 2;
            if(binarysearch(s, m, k)) l = m + 1;
            else h = m - 1;
        }
        return l - 1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends