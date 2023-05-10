//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int ans = 0;
        int i = 0, j = s.size() - 1;
        string str = "";
        while(i < j) {
            if(s[i] != s[j] && s[j] != '?' && s[i] != '?') {
                return -1;
            } else if(s[i] != '?') {
                str += s[i];
            } else if(s[j] != '?') {
                str += s[j];
            } 
            i++;
            j--;
        }
        if(str != "") for(int i = 0; i < str.size() - 1; i++) {
            ans += abs(str[i + 1] - str[i]);
        }
        return ans * 2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends