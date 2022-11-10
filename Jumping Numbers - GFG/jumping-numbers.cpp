//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long ans=0;
    void solve(long long cur, long long x){
        if(cur>x)
            return ;
        ans=max(cur,ans);
        if(cur%10==0)
            solve(cur*10+1,x);
        else if(cur%10==9)
            solve(cur*10+8,x);
        else{
            solve(cur*10+cur%10-1,x);
            solve(cur*10+cur%10+1,x);
        }
        return ;
    }
    long long jumpingNums(long long x) {
        if(x<=10)
            return x;
        for(int i=1;i<=9;i++){
            solve(i,x);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends