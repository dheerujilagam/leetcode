//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>st;
    for(auto it:num){
        while(!st.empty() and st.top()>it and k>0){
            st.pop();
            k--;
        }
        if(!st.empty() or it!='0') st.push(it);
    }
    while(k>0 and !st.empty()){
        st.pop();
        k--;
    }
    string res;
    while(!st.empty()){
        res=st.top()+res;
        st.pop();
    }
    if(res.size()==0) return "0";
    return res;
    
}