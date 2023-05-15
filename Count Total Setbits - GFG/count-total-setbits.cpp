//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) {
        long long ans = 0;
        int n1 = 1;
        int n2 = 1 << n1;
        for(int i = 0; i < 31; i++) {
            ans += (n / n2) * n1;
            int rem = (n % n2) - n1 + 1;
            if(rem > 0) ans += rem;
            n1 <<= 1;
            n2 <<= 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends