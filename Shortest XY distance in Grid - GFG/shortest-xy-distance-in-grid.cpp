//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> moves{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        // code here
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') q.push({0, {i, j}}), vis[i][j] = 1;
            }
        }
        while(!q.empty()) {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int x = p.second.first, y = p.second.second, dis = p.first;
            if(grid[x][y] == 'Y') return dis;
            for(auto it : moves) {
                if(x + it[0] < 0 || x + it[0] >= n || y + it[1] < 0 || y + it[1] >= m ||grid[x + it[0]][y + it[1]] == 'X' || vis[x + it[0]][y + it[1]]) continue;
                // grid[x + it[0]][y + it[1]] = ''
                vis[x + it[0]][y + it[1]] = 1;
                q.push({dis + 1, {x + it[0], y + it[1]}});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends