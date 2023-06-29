//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool happy(int n) {
        if(n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) return false;
        if(n == 1) return true;
        int sum = 0;
        while(n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return happy(sum);
    }
    int nextHappy(int N){
        // code here
        ++N;
        while(N <= 1e5) {
            if(happy(N)) {
                return N;
            }
            N++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends