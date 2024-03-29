//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> geek) {
        long long sum=0;
        for(int i=0;i<k;i++)
            sum+=geek[i];
        //geek.push_back(sum);
        int i=k,j=0;
        while(i<n){
            geek.push_back(sum);
            sum-=geek[j++];
            sum+=geek[i++];
        }
        return geek[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends