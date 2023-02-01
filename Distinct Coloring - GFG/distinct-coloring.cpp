//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        // code here 
        long long int x[n],y[n],z[n];
        for(int i=0;i<n;i++)
            x[i]=r[i];
        for(int i=0;i<n;i++)
            y[i]=g[i];
        for(int i=0;i<n;i++)
            z[i]=b[i];
        for(int i=1;i<n;i++){
            x[i]+=min(y[i-1],z[i-1]);
            y[i]+=min(x[i-1],z[i-1]);
            z[i]+=min(x[i-1],y[i-1]);
        }
        return min({x[n-1],y[n-1],z[n-1]});
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends