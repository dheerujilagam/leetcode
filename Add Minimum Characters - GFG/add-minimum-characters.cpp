//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool check(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int addMinChar(string str){
        int i = 0, j = str.size() - 1, ans = 0;
        while(i < j) {
            if(check(str.substr(i, j - i + 1))) {
                i = j;
            }
            else j--, ans++;
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
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends