//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution {
    
  public:
  
    int solve(int id, int n, int x, int y, int k ,int a[], vector<bool> vis) {
         if (k == 0)
            return true;
         if (x == y)
            return solve(0, n, 0, y, k - 1, a, vis);
         for(int i = id; i < n; i++) {
             if (vis[i] == false) {
                 if(x + a[i] <= y) {
                     vis[i] = true;
                     if(solve(i + 1, n, x + a[i], y, k, a, vis)) return true;
                     vis[i] = false;
                 }
             }
         }
         return false;
    }
    
    bool isKPartitionPossible(int a[], int n, int k) {
         //Your code here
         int sum = 0;
         for (int i = 0;i < n; i++) sum  += a[i];
         if (sum % k != 0)
            return false;
         vector<bool> vis(n, false);
         int r = sum / k;
         return solve(0, n, 0, r, k, a, vis);
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends