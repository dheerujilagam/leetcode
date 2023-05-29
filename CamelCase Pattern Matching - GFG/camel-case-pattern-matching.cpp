//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> dict, string p) {
        // code here
        unordered_map<string, vector<string>> st;
        for(string it : dict) {
            string t = "";
            for(char i : it) {
                if(i >= 'A' && i <= 'Z') t += i, st[t].push_back(it);
            }
        }
        if(st.find(p) != st.end()) return st[p];
        return {"-1"};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends