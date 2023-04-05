//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        int count = 0, mx = *max_element(arr.begin(), arr.end());
        vector<int> dp(mx + 1, 0);
        for(int it : arr) {
            if(dp[it] <= 1) for(int i = it; i <= mx; i += it) dp[i]++;
        }
        for(int it : arr) if(dp[it] > 1) count++;
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends