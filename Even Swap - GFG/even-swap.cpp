//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        vector<int> lexicographicallyLargest(vector<int> &a, int n){
            vector<int> ans;
            vector<int> cur;
            int flag;
            for(int it : a) {
                if(cur.size() == 0) {
                    if(it & 1) flag = 1, cur.push_back(it);
                    else flag = 0, cur.push_back(it);
                } else {
                    if((it & 1) && flag) {
                        cur.push_back(it);
                    } else if(!(it & 1) && flag) {
                        sort(cur.rbegin(), cur.rend());
                        for(int val : cur) ans.push_back(val);
                        cur.clear();
                        cur.push_back(it);
                        flag = 0;
                    } else if(!(it & 1) && !flag) {
                        cur.push_back(it);
                    } else {
                        sort(cur.rbegin(), cur.rend());
                        for(int val : cur) ans.push_back(val);
                        cur.clear();
                        cur.push_back(it);
                        flag = 1;
                    }
                }
            }
            if(cur.size() != 0) {
                sort(cur.rbegin(), cur.rend());
                for(int val : cur) ans.push_back(val);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends