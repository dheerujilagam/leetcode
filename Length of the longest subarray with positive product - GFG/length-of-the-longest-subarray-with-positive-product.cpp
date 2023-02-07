//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           int c=0,mx=0,stN=-1,endN=-1,ZeroN=-1;
           for(int i=0;i<n;i++){
               if(arr[i]==0){
                   if(c&1){
                       mx=max(mx,stN-ZeroN-1);
                       mx=max(mx,i-1-stN);
                       mx=max(mx,i-1-endN);
                       mx=max(mx,endN-ZeroN-1);
                   }
                   else{
                       mx=max(mx,i-1-ZeroN);
                   }
                   ZeroN=i;
                   c=0;
                   stN=i;
                   endN=i;
               }
               else{
                   if(arr[i]<0){
                       if(c){
                           endN=i;
                       }
                       else{
                           stN=endN=i;
                       }
                       c++;
                   }
               }
           }
           if(c&1){
               mx=max(mx,stN-ZeroN-1);
               mx=max(mx,n-1-stN);
               mx=max(mx,n-1-endN);
               mx=max(mx,endN-ZeroN-1);
           }
           else{
               mx=max(mx,n-1-ZeroN);
           }
           return mx;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends