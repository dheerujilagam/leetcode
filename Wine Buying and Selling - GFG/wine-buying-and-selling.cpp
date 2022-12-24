//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      priority_queue<pair<int,int>>x,y;
      for(int i=0;i<N;i++){
          if(Arr[i]>0){
              x.push({i,Arr[i]});
          }
          else{
              y.push({i,abs(Arr[i])});
          }
      }
      long long int cost=0;
      pair<int,int>a,b;
      while(!x.empty() && !y.empty()){
          a=x.top();
          b=y.top();
          x.pop();
          y.pop();
          if(a.second==b.second){
              cost+=a.second*abs(a.first-b.first);
          }
          else if(a.second>b.second){
              cost+=b.second*abs(a.first-b.first);
              x.push({a.first,a.second-b.second});
          }
          else{
              cost+=a.second*abs(a.first-b.first);
              y.push({b.first,b.second-a.second});
          }
      }
      return cost;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends