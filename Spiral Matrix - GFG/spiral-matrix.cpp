//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &mat, int n, int m, int k)
    {
        // Your code goes here
        int sr=0,sc=0,er=n,ec=m;
        vector<int>v;
        while((sr<er) and (sc<ec)){
            for(int i=sc;i<ec;i++)
                v.push_back(mat[sr][i]);
            sr++;
            for(int i=sr;i<er;i++)
                v.push_back(mat[i][ec-1]);
            ec--;
            if(sr<er){
                for(int i=ec-1;i>=sc;i--)
                    v.push_back(mat[er-1][i]);
                er--;
            }
            if(sc<ec){
                for(int i=er-1;i>=sr;i--)
                    v.push_back(mat[i][sc]);
                sc++;
            }
        }
        return v[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends