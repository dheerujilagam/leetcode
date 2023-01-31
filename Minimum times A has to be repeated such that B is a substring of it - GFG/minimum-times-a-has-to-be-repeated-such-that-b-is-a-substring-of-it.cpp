//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        string t=a;
        int c=1;
        while(a.size()<b.size()){
            a+=t;
            c++;
        }
        if(a.find(b)!=std::string::npos)
            return c;
        a+=t;
        c++;
        if(a.find(b)!=std::string::npos)
            return c;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends