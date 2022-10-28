//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int>ans;
    struct Node{
        int data;
        Node *left, *right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
    };
    Node* insert(Node *root, int val, int mx){
        if(!root){
            ans.push_back(mx);
            return new Node(val);
        }
        if(val>=root->data)
            root->right=insert(root->right,val,mx);
        else{
            mx=root->data;
            root->left=insert(root->left,val,mx);
        }
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        ans.clear();
        Node *root=NULL;
        for(int i=n-1;i>=0;i--){
            root=insert(root,arr[i],-1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
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
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends