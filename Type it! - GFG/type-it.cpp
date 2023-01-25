//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n=s.size(),mx=0;
        string st="";
        for(int i=0;i<=n/2;i++){
            int flag=1;
            if(st!="" && st[0]==s[i]){
                for(int j=0;j<i;j++){
                    if(s[j]!=s[j+i]){
                        flag=0;
                        break;       
                    }
                }
                if(flag)
                    mx=i;
            }
            st+=s[i];
        }
        if(mx==0)   
            return n;
        return n-mx+1;
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends