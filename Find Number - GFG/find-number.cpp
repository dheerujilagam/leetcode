//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int pos[5] = {1, 3, 5, 7, 9};
    long long findNumber(long long n){
        if(n <= 5) return pos[n - 1];
        if(n % 5 == 0) return findNumber(n / 5 - 1) * 10 + 9;
        return findNumber(n / 5) * 10 + pos[n % 5 - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends