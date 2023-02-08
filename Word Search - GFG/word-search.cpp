//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i, int j, int n, int m, vector<vector<char>> &board, string &s, int id){
        if(id==s.size())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || s[id]!=board[i][j])
            return false;
        char temp=s[id];
        board[i][j]='#';
        if(dfs(i+1,j,n,m,board,s,id+1) | dfs(i-1,j,n,m,board,s,id+1) | dfs(i,j+1,n,m,board,s,id+1) | dfs(i,j-1,n,m,board,s,id+1))
            return true;
        board[i][j]=temp;
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,n,m,board,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends