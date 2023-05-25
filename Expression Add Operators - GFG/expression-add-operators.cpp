//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> addOperators(string s, int target) {
        // code here
        vector<string> res;
        solve(s, target, "", 0, 0, 0, res);
        return res;
    }
  private:
    void solve(string &s, int target, string expression, int id, long curVal, long preVal, vector<string> &res) {
        if(id == s.length()) {
            if(curVal == target) res.push_back(expression);
            return ;
        }
        for(int i = id; i < s.length(); i++) {
            if(i != id && s[id] == '0') break;
            long num = stol(s.substr(id, i - id + 1));
            if(id == 0) solve(s, target, to_string(num), i + 1, num, num, res);
            else {
                solve(s, target, expression + '+' + to_string(num), i + 1, curVal + num, num, res);
                solve(s, target, expression + '-' + to_string(num), i + 1, curVal - num, -num, res);
                solve(s, target, expression + '*' + to_string(num) , i + 1, curVal - preVal + preVal * num, preVal * num, res);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends