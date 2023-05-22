//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        // code here
        vector<int> dp(n + 1, 0);
        int count  = 0;
        for(int i = 1; i < n; i++) dp[p[i]]++;
        for(int i = 1; i <= n; i++) if(dp[i] >= 1) count++;
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends