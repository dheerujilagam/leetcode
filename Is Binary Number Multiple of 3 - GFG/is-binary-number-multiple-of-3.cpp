//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isDivisible(string s){
	    int ans = 0;
	    for(int i = s.length() - 1; i >= 0; i--) {
	        if(s[i] == '1') {
	            if((s.length() - i - 1) % 2 == 0) ans += 1;
	            else ans += 2;
	        }
	        ans %= 3;
	    }
	    return ans == 0 ? 1 : 0;
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends