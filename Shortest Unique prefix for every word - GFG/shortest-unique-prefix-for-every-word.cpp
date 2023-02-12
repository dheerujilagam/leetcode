//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct TrieNode{
    	TrieNode *child[26];
    	int cnt;
    	TrieNode(){
    	    cnt=0;
    		for(int i=0;i<26;i++)
    			child[i]=NULL;
    	}
    };
    
    void insert(TrieNode* root, string &key){
    	TrieNode* cur=root;
    	for(char it:key){
    		if(cur->child[it-'a']==NULL){
    			cur->child[it-'a']=new TrieNode();
    		}
    		cur->cnt++;
    		cur=cur->child[it-'a'];
    	}
    }
    
    string search(TrieNode* root, string &key){
    	TrieNode* cur=root;
    	string res="";
    	for(char it:key){
    		if(cur->child[it-'a']==NULL || cur->cnt==1)
    		    break;
    		res+=it;
    		cur=cur->child[it-'a'];
    	}
    	return res;
    }

    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++)
            insert(root,arr[i]);
        vector<string>ans;
        for(int i=0;i<n;i++){
            ans.push_back(search(root,arr[i]));
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends