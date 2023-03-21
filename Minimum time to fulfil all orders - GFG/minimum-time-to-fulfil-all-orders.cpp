//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool check(int n, vector<int> &a, int mid) {
        int count = 0;
        for(int it : a) {
            int i = 1, cnt = 0;
            while(cnt + (it * i) <= mid) {
                cnt += (it * i++);
                count++;
            }
            if(count >= n) return true;
        }
        return false;
    }
    int findMinTime(int n, vector<int>&a, int l) {
        //write your code here
        int left = 0, right = 1e9;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(check(n, a, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends