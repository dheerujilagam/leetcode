//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        vector<int>ans;
        int sr=0,sc=0,er=r,ec=c;
        while ((sr<er) && (sc<ec)){
            for(int i=sc;i<ec;i++)
                ans.push_back(mat[sr][i]);
            sr++;
            for(int i=sr;i<er;i++)
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
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends