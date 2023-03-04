//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
    long long ans = LLONG_MIN;
    
    void dfs(int node, vector<int> &ar, vector<int> &p, long long a, long long b, int l, int r) {
        a += (l * ar[node]);
        b += (r * ar[node]);
        if(l == 1) ans = max(ans, a);
        else ans = max(ans, b);
        if(p[node] == -1) return ;
        dfs(p[node] - 1, ar, p, a, b, -1 * l, -1 * r);
    }
    
    long long bestNode(int n, vector<int> &a, vector<int> &p) {
        // code here
        unordered_set<int> s;
        ans = LLONG_MIN;
        for(int i : p) s.insert(i);
        for(int i = 1; i <= n; i++) {
            if(!s.count(i)) dfs(i - 1, a, p, 0, 0, 1, -1);
        }
        return ans;
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
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends