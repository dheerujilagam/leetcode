//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int i = 0, j = 0, n = s.length(), m = t.length();
        while(i < n && j < m){
            if(isdigit(t[j])){
                int val = 0;
                while(j < m && isdigit(t[j])){
                    val = (val * 10) + t[j] - '0';
                    j++;
                }
                i += val;
            }
            else{
                if(s[i] != t[j])
                    return 0;
                i++;
                j++;
            }
        }
        return i == n && j == m;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends