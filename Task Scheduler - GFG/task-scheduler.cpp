//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        if(k == 0) return n;
        vector<int> freq(26, 0);
        int c = 0, ct = 0;
        for(char it : tasks) {
            freq[it - 'A']++;
            c = max(c, freq[it - 'A']);
        }
        for(int i = 0; i < 26; i++) if(c == freq[i]) ct++;
        int ans = c + ct - 1 + ((c - 1) *k);
        return ans < n ? n : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends