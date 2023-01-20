//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> Edge)
  {
      // code here
      map<int,int,greater<int>>arr;
      for(int i=0;i<n;i++){
          arr[Edge[i]]+=i;
      }
      int cell=0,mx=0;
      for(auto it:arr){
          if(it.first!=-1 && mx<=it.second){
              cell=it.first;
              mx=it.second;
          }
      }
      return cell;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends