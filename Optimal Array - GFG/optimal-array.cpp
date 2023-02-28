//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        int premedian = -1;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int median = 0;
            int size = i + 1;
            if(size % 2 == 0) median = (a[(size / 2) - 1] + a[size / 2]) / 2;
            else median = a[size / 2];
            int moves = 0;
            if(premedian == median) moves += ans.back(), moves += abs(a[i] - median);
            else for (int j = 0; j <= i; j++) moves += abs(a[j] - median);
            ans.push_back(moves);
            premedian = median;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends