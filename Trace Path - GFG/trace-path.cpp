//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        int x = 0, y = 0;
        for(char it : s) {
            if(it == 'L') {
                y -= 1;
            } else if(it == 'R') {
                y += 1;
            } else if(it == 'U') {
                x += 1;
            } else {
                x -= 1;
            }
            minx = min(minx, x);
            miny = min(miny, y);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
            if(abs(minx - maxx) >= n || abs(miny - maxy) >= m || abs(x) >= n || abs(y) >= m) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends