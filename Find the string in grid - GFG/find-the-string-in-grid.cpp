//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int x[8] = {1, 0, 0, -1, 1, -1, -1, 1}, y[8] = {0, -1, 1, 0, 1, 1, -1, -1};
    bool solve(int k, int i, int j, vector<vector<char>> &grid, string &word, int dir) {
        if(k == word.length() - 1) return true;
        int px = i + x[dir], py = j + y[dir];
        bool flag = false;
        if(px >= 0 && py >= 0 && px < grid.size() && py < grid[0].size() && grid[px][py] == word[k + 1]) {
            flag |= solve(k + 1, px, py, grid, word, dir);
        }
        return flag;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> res;
	    int n = grid.size(), m = grid[0].size();
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(grid[i][j] == word[0]) {
	                for(int k = 0; k < 8; k++) {
	                    int px = i + x[k], py = j + y[k];
	                    if(solve(0, i, j, grid, word, k)) {
	                        res.push_back({i, j});
	                        break;
	                    }
	                }
	            }  
	        }
	    }
	    sort(res.begin(), res.end());
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends