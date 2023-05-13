//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int id, int n, int prev, vector<int> &a, vector<vector<long long>> &dp) {
        if(id >= n) return 0;
        if(dp[id][prev] != -1) return dp[id][prev];
        long long inc, exc;
        if(prev == 0) {
            inc = a[id] + solve(id + 1, n, 1, a, dp);
            exc = LLONG_MIN;
        } else {
            inc = a[id] + solve(id + 1, n, 1, a, dp);
            exc = solve(id + 1, n, 0, a, dp);
        }
        return dp[id][prev] = max(inc, exc);
    }
    long long findMaxSubsetSum(int n, vector<int> &a) {
        // code here
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return max(solve(0, n, 0, a, dp), solve(0, n, 1, a, dp));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends