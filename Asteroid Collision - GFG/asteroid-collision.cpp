//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &ast) {
        // code here
        stack<int>st;
        for(int i=0;i<N;i++){
            if(ast[i]>0 or st.empty()){
                st.push(ast[i]);
            }
            else{
                if(ast[i]<0){
                    while(!st.empty() and st.top()>0 and st.top()<abs(ast[i])){
                        st.pop();
                    }
                    if(!st.empty() and st.top()==abs(ast[i])){
                        st.pop();
                    }
                    else if(st.empty() or st.top()<0){
                        st.push(ast[i]);
                    }
                }
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends