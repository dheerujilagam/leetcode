//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int n, int q, vector<vector<int>> &u)
        {
            // code here
            vector<int>ans(n, 0);
            vector<vector<int>> prev(n + 1, vector<int> (32, 0));
            for (int i = 0; i < q; i++) {
                int l = u[i][0], r = u[i][1], val = u[i][2];
                for (int j = 0; j < 32; j++) {
                    if ((1 << j) & val) {
                        prev[l - 1][j]++;
                        prev[r][j]--;
                    }
                }
            }
            for (int i = 1; i < n; i++) for (int j = 0; j < 32; j++) prev[i][j] += prev[i - 1][j];
            for (int i = 0; i < n; i++) {
                int val = 0;
                for (int j = 0; j < 32; j++) if (prev[i][j]) val += (1 << j);
                ans[i] = val;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends