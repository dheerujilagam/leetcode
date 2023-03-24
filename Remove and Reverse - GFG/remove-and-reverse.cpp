//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        vector<int> dp(26, 0);
        for(char it : s) dp[it - 'a']++;
        int i = 0, j = s.size() - 1;
        bool flag = false;
        while(i < j) {
            if(flag) {
                if(dp[s[j] - 'a'] > 1) {
                    dp[s[j] - 'a']--;
                    s[j] = '#';
                    flag = false;
                }
                else dp[s[j] - 'a']--;
                j--;
                
            }
            else {
                if(dp[s[i] - 'a'] > 1) {
                    dp[s[i] - 'a']--;
                    s[i] = '#';
                    flag = true;
                }
                else dp[s[i] - 'a']--;
                i++;
            }
            // cout << s << endl;
        }
        // cout << s << endl;
        string ans = "";
        for(char it : s) if(it != '#') ans += it; 
        if(flag) reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends