//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char> res;
        for(auto it : queries) {
            if(it[0] == "1") {
                s[stoi(it[1])] = it[2][0];
            } else {
                int l = stoi(it[1]), r = stoi(it[2]), k = stoi(it[3]);
                int count[26] = {0};
                for(int i = l; i <= r; i++) count[s[i] - 'a']++;
                char ch;
                int pos = 0;
                for(int i = 25; i >= 0; i--) {
                    pos += count[i];
                    if(pos >= k) {
                        ch = i + 'a';
                        break;
                    }
                }
                res.push_back(ch);
            }
        }
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
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends