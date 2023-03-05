//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int parent[1000];
    void SetData() {
    	for(int i = 0; i < 1000; i++){
    		parent[i] = i;
    	}
    }
    
    int FindParent(int node) {
    	if(parent[node] == node) 
    		return node;
    	return parent[node] = FindParent(parent[node]);
    }
    
    void Union(int u, int v){
    	u = FindParent(u);
    	v = FindParent(v);
    	if(u == v) return ;
    	parent[u] = parent[v];
    }
    
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
        vector<string> ans(n);
        SetData();
        for(int i = 0; i < n; i++) {
            int p1 = FindParent(mix[i][0]), p2 = FindParent(mix[i][1]);
            bool flag = true;
            for(int j = 0; j < m; j++) {
                int d1 = FindParent(danger[j][0]), d2 = FindParent(danger[j][1]);
                if((p1 == d1 && p2 == d2) || (p1 == d2 && p2 == d1)) {flag = false; break;}
            }
            if(flag) Union(p1, p2), ans[i] = "Yes";
            else ans[i] = "No";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends