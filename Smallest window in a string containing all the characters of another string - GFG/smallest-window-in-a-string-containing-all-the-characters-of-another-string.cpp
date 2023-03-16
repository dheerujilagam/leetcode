//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    bool check(vector<int> &c1, vector<int> &c2) {
        for(int i = 0; i < 26; i++) if(c1[i] < c2[i]) return false;
        return true;
    }
    
    string smallestWindow (string s, string p) {
        
        int i = 0, j = 0, l = 0, r = INT_MAX, n = s.size(), m = p.size();
        
        if(n < m) return "-1";
        
        vector<int> c1(26, 0), c2(26, 0);
        
        for(char it : p) {c2[it - 'a']++;}
        
        string res = "";
        
        while(j < n) {
            
            c1[s[j++] - 'a']++;
            
            while(check(c1, c2)) {
                
                if(r - l > j - i) r = j, l = i;
                
                c1[s[i] - 'a']--;
                
                i++;
            }
        }
        return r == INT_MAX ? "-1" : s.substr(l, r - l);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends