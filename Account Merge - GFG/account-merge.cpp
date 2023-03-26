//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int parent[1001],  size[1001];
    void UnionFind() {
        for(int i = 0; i <= 1000; i++) parent[i] = i;
    }
    
    int FindParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = FindParent(parent[n]);
    }
    
    void Union(int u, int v) {
        u = FindParent(u); 
        v = FindParent(v);
        if(u < v) {
            parent[u] = v;
            size[v] += size[u];
        }
        else if(v < u) {
            parent[v] = u;
            size[u] += size[v];
        }
        return ;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        UnionFind();
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp.find(accounts[i][j]) == mp.end()) mp[accounts[i][j]] = i;
                else Union(i, mp[accounts[i][j]]);
            }
        }
        vector<string> dp[n];
        for(auto it : mp) dp[FindParent(it.second)].push_back(it.first);
        for(int i = 0; i < n; i++) {
            if(dp[i].size() > 0) {
                vector<string> t = dp[i];
                sort(t.begin(), t.end());
                t.insert(t.begin() + 0, accounts[i][0]);
                ans.push_back(t);
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends