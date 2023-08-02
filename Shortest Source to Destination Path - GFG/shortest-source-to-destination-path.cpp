//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> arr, int x, int y) {
        // code here
        if(arr[0][0] == 0 || arr[x][y] == 0) return -1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                pair<int, int> p = q.front();
                q.pop();
                if(p.first == x && p.second == y) return ans;
                for(int i = 0; i < 4; i++) {
                    int a = p.first + dx[i], b = p.second + dy[i];
                    if(a >= 0 && b >= 0 && a < n && b < m && arr[a][b]) {
                        arr[a][b] = 0;
                        q.push({a, b});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends