//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res;
        while (n > 0) {
            if (n % 26 == 0) {
                res.push_back('Z');
                n = (n - 1) / 26;
            } else {
                int cur = n % 26;
                res.push_back('A' + cur - 1);
                n /= 26;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends