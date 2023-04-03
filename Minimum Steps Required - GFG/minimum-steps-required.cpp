//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    char prev = '#';
    int aC = 0, bC = 0;
    for(char it : str) {
        if(prev != it) {
            prev = it;
            if(it == 'a') aC++;
            else bC++;
        }
    }
    return min(aC, bC) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends