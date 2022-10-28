//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // vector<int>ans;
    // bool leafs(int &i, int n, int arr[], int min, int max){
    //     if(i>=n or arr[i]<min or arr[i]>max)
    //         return false;
    //     int temp=arr[i];
    //     i++;
    //     bool l=leafs(i,n,arr,min,temp);
    //     bool  r=leafs(i,n,arr,temp,max);
    //     if(!l and !r)
    //         ans.push_back(temp);
    //     return true;
    // }
    struct Node{
        int data;
        Node *left, *right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
    };
    Node* insert(Node *root, int val){
        if(!root){
            return new Node(val);
        }
        if(val>=root->data)
            root->right=insert(root->right,val);
        else{
            root->left=insert(root->left,val);
        }
    }
    void tra(Node *root,vector<int>&ans){
        if(root){
            if(!root->left and !root->right)
                ans.push_back(root->data);
            tra(root->left,ans);
            tra(root->right,ans);
        }
        return ;
    }
    vector<int> leafNodes(int arr[],int n) {
        vector<int>ans;
        Node *root=NULL;
        for(int i=0;i<n;i++){
            root=insert(root,arr[i]);
        }
        tra(root,ans);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends