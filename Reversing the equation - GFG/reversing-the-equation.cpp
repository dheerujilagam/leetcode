//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s) {
        string res = "";
        int j = s.length() - 1, i;
        for(i = s.length() - 1; i >= 0; i--) {
            if(!isdigit(s[i])) {
                res += s.substr(i + 1, j - i);
                res += s[i];
                j = i - 1;
            }
            if(i == 0) {
                res += s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends