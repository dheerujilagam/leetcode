//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int n) {
        // Code here
        long long int cnt=0;
        //priority_queue<int,vector<int>,greater<int>>pq;
        sort(arr.begin(),arr.end());
        set<int>s;
        for(int i=0;i<n;i++){
            if(s.count(arr[i])){
                int k=1;
                while(true){
                    if(s.count(arr[i]+k)){
                        k++;
                    }
                    else{
                        s.insert(arr[i]+k);
                        cnt+=k;
                        break;
                    }
                }
            }
            else
                s.insert(arr[i]);
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends