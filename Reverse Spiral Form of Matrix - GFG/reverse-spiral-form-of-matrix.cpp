//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&mat)  {
        vector<int>ans;
        int sr=0,sc=0,er=r,ec=c;
        while ((sr<er) && (sc<ec)){
            for(int i=sc;i<=ec-1;i++)
                ans.push_back(mat[sr][i]);
            sr++;
            for(int i=sr;i<=er-1;i++)
                ans.push_back(mat[i][ec-1]);
            ec--;
            if(sr<er){
                for(int i=ec-1;i>=sc;i--)
                    ans.push_back(mat[er-1][i]);
                er--;
            }
            if(sc<ec){
                for(int i=er-1;i>=sr;i--)
                    ans.push_back(mat[i][sc]);
                sc++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends