//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int gs, vector<int> &arr) {
        // code here
        if(n % gs != 0) return false;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for(int it : arr) mp[it]++;
        for(int it : arr) {
            int cnt = gs, val = it;
            while(mp.find(val) != mp.end() && cnt > 0) {
                mp[val] -= 1;
                cnt -= 1;
                if(mp[val] == 0) mp.erase(val);
                val += 1;
            }
            if(cnt != 0 && cnt != gs) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends