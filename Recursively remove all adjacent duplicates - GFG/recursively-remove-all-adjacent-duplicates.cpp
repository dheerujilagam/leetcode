//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        string cur="";
        int i=0,n=s.size();
        while(i<n){
            if(s[i]!=s[i+1])
                cur+=s[i];
            else{
                while(s[i]==s[i+1])
                    i++;
            }
            i++;
        }
        if(s==cur)
            return s;
        return rremove(cur);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends