//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string>s1;
        stack<int>s2;
        string cur="";
        int n=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                n=(n*10)+s[i]-'0';
            else if(s[i]>='a' and s[i]<='z')
                cur+=s[i];
            else if(s[i]=='['){
                s1.push(cur);
                s2.push(n);
                cur="";
                n=0;
            }
            else{
                string t="";
                int op=s2.top();
                for(int j=0;j<op;j++)
                    t+=cur;
                cur=s1.top()+t;
                s1.pop();
                s2.pop();
            }
        }
        return cur;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends