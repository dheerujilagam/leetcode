//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<int> adj[], vector<int>&dis, int pos, int moves){
        if(pos>=30){
            dis[30]=min(dis[30],moves+1);
            return ;
        }
        dis[pos]=min(dis[pos],moves+1);
        for(int i=1;i<=6;i++){
            if(adj[pos+i].size()!=0 and pos+i<=30 and dis[pos+i]>=moves+1){
                dis[pos+i]=moves+1;
                solve(adj,dis,adj[pos+i][0],moves+1);
            }
        }
        if(pos+6>30)
            solve(adj,dis,30,moves+1);
        else
            solve(adj,dis,pos+6,moves+1);
        return ;
    }
    int minThrow(int n, int arr[]){
        vector<int>adj[31],dis(31,INT_MAX);
        for(int i=0;i<2*n;i+=2){
            adj[arr[i]].push_back(arr[i+1]);
        }
        solve(adj,dis,1,0);
        return dis[30]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends