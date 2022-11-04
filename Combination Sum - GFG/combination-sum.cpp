//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int id, vector<int>&dig, vector<vector<int>>&res, vector<int>t, int sum, int target){
        if(sum>target)
            return ;
        if(sum==target){
            res.push_back(t);
            return ;
        }
        for(int i=id;i<dig.size();i++){
            t.push_back(dig[i]);
            sum+=dig[i];
            solve(i,dig,res,t,sum,target);
            sum-=dig[i];
            t.pop_back();
        }
        return ;
    }
    vector<vector<int> > combinationSum(vector<int> &dig, int k) {
        // Your code here
        set<int>s(dig.begin(),dig.end());
        vector<int>can(s.begin(),s.end());
        vector<vector<int>>res;
        vector<int>t;
        int sum=0;
        solve(0,can,res,t,sum,k);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends