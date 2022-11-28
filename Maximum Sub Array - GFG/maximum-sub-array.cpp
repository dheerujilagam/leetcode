//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int nums[], int n) {
	    int st=0,end=-1,sum=0,tem=0,i=0,j=0,dif=0;
	    while(j<n){
	        if(nums[j]>=0){
	            tem+=nums[j];
	        }
	        else{
	            if((sum==tem && dif<j-i-1) || (sum<tem)){
	                sum=tem;
	                st=i;
	                end=j-1;
	                dif=end-st;
	            }
	            tem=0;
	            i=j+1;
	        }
	        j++;
	    }
	    if((sum==tem && dif<j-i-1) || (sum<tem)){
            sum=tem;
            st=i;
            end=j-1;
            dif=end-st;
        }
        vector<int>res;
        for(int i=st;i<=end;i++)
            res.push_back(nums[i]);
        if(res.size()==0) return {-1};
        return res;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

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
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends