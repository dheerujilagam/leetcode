//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        // Code here
        vector<bool> moves(leaves + 1, true);
        for(int i = 0; i < n; i++) {
            if(moves[frogs[i]]) {
                for(int j = frogs[i]; j <= leaves; j += frogs[i]) {
                    moves[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 1; i <= leaves; i++) if(moves[i]) count++;
        return count;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends