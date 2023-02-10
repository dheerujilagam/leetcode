//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int>v(26,0);
        for(char it:s)
            v[it-'a']++;
        v['l'-'a']/=2;
        v['o'-'a']/=2;
        return min({v['b'-'a'],v['a'-'a'],v['l'-'a'],v['o'-'a'],v['n'-'a']});
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends