//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MOD = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<bool> vis(1e5 + 1, false);
        vis[start] = true;
        queue<int> q;
        q.push(start);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int cur = q.front();
                q.pop();
                if (cur == end) {
                    return ans;
                }
                for (int it : arr) {
                    int x = (it * cur) % MOD;
                    if (!vis[x]) {
                        q.push(x);
                        vis[x] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends