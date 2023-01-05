//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        set<string>s;
        for(auto it:words)
            s.insert(it);
        string ans;
        sort(words.begin(),words.end());
        for(auto it:words){
            string t=it,tem="";
            bool flag=true;
            for(auto i:t){
                tem+=i;
                if(s.find(tem)==s.end()){
                    flag=false;
                    break;
                }
            }
            if(flag and t.size()>ans.size()){
                ans=t;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends