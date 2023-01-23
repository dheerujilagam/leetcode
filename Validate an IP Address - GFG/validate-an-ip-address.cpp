//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int n=s.size();
            if(n>15)
                return 0;
            string t="";
            int c=0;
            for(int i=0;i<n;i++){
                if(s[i]=='.'){
                    c++;
                    if(t=="")
                        return 0;
                    if(stoi(t)>255)
                        return 0;
                    if(t.size()>=2 && t[0]=='0')
                        return 0;
                    else
                        t="";
                }
                else{
                    if(s[i]-'0'>=0 && s[i]-'0'<=9)
                        t+=s[i];
                    else
                        return 0;
                }
                
            }
            if(t=="")
                return 0;
            if(stoi(t)>255)
                return 0;
            if(t.size()>=2 && t[0]=='0')
                return 0;
            if(c!=3)
                return 0;
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends