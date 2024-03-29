//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int nums[n];
        nums[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            nums[i] = max(arr[i], nums[i + 1]);
        }
        int cnt = 0, i = 0, j = 0;
        while(i < n && j < n) {
            if(arr[i] <= nums[j]) {
                cnt = max(cnt, j - i);
                j++;
            } else {
                i++;
            }
        }
        return cnt;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends