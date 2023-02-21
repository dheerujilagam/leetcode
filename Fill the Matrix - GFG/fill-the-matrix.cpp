//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        vector<vector<int>> grid(n, vector<int> (m, 0));
        grid[x - 1][y - 1] = 1;
        vector<vector<int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>> q;
        q.push({x - 1, y - 1});
        int cnt=0;
        while(!q.empty()) {
            int len = q.size(), flag = 0;
            while(len--){
                int sx = q.front().first, sy = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int a = sx + moves[i][0], b = sy + moves[i][1];
                    if(a < 0 || a >= n || b < 0 || b >= m || grid[a][b])
                        continue;
                    q.push({a, b});
                    grid[a][b]=1;
                    flag = 1;
                }
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends