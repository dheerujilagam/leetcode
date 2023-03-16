//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        if(d == 1 || s == 1 || s >= (9 * d)) return "-1";
        int dp[d];
        dp[0] = 1;
        s -= 1;
        for(int i = d - 1; i >= 1; i--) {
            if(s > 9) dp[i] = 9, s -= 9;
            else dp[i] = s, s = 0;
            // cout << dp[i] << " ";
        }
        if(s != 0) dp[0] += s;
        // for(int i = 0; i < d; i++) cout << dp[i] << " ";
        for(int i = d - 1; i >= 1; i--) {
            if(dp[i] != dp[i - 1]) {
                dp[i]--;
                dp[i - 1]++;
                break;
            }
        }
        string ans = "";
        for(int i = 0; i < d; i++) ans += to_string(dp[i]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends