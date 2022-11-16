//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int c=0,n=s.size();
        for(int i=0;i<n;i++){
            map<char,int>mp;
            //multiset<int>ms;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int mn=INT_MAX,mx=0;
                for(auto it:mp){
                    if(mx<it.second)
                        mx=it.second;
                    if(mn>it.second)
                        mn=it.second;
                }
                c+=mx-mn;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends