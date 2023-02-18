//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string s){
        int st=0,end=0,mx=0;
        while(end<n){
            if(s[end]=='O'){
                if(m>=0)
                    m--;
            }
            while(m<0){
                if(s[st++]=='O')
                    m++;
            }
            mx=max(mx,end-st+1);
            end++;
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends