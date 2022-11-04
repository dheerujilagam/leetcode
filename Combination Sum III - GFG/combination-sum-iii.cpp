//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i,int cur, int k, int n, vector<int>can, vector<vector<int>>&res, vector<int>t){
        if(cur>n)
            return ;
        if(cur==n and t.size()==k){
            res.push_back(t);
            return ;
        }
        for(int j=i;j<9;j++){
            t.push_back(can[j]);
            cur+=can[j];
            solve(j+1,cur,k,n,can,res,t);
            t.pop_back();
            cur-=can[j];
        }
        return ;
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int>can{1,2,3,4,5,6,7,8,9};
        vector<vector<int>>res;
        vector<int>t;
        solve(0,0,K,N,can,res,t);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends