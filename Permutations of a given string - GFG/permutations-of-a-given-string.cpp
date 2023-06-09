//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> res;
	    void solve(int id, int n, string s) {
	        if(id == n) {
	            res.insert(s);
	            return ;
	        }
	        for(int i = id; i <= n; i++) {
	            swap(s[id], s[i]);
	            solve(id + 1, n, s);
	            swap(s[id], s[i]);
	        }
	        return ;
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    res.clear();
		    int n = s.length();
		    solve(0, n - 1, s);
		    vector<string> ans(res.begin(), res.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends