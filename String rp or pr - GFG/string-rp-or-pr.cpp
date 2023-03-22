//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x,int y,string s){
      //code here
      int n = s.size();
      stack<char> st;
      long long ans = 0;
      if(x > y) {
          for(int i = 0; i < n; i++) {
              if(st.empty()) st.push(s[i]);
              else if(st.top() == 'p' && s[i] == 'r') st.pop(), ans += x;
              else st.push(s[i]);
          }
          int flag = 0;
          while(!st.empty()) {
              if(st.top() == 'p') flag++, st.pop();
              else if(st.top() == 'r' && flag > 0) ans += y, flag--, st.pop();
              else st.pop(), flag = 0;
          }
      }
      else {
          for(int i = 0; i < n; i++) {
              if(st.empty()) st.push(s[i]);
              else if(st.top() == 'r' && s[i] == 'p') st.pop(), ans += y;
              else st.push(s[i]);
          }
          int flag = 0;
          while(!st.empty()) {
              if(st.top() == 'r') flag++, st.pop();
              else if(st.top() == 'p' && flag > 0) ans += x, flag--, st.pop();
              else st.pop(), flag = 0;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends