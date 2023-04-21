//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    struct TrieNode {
    	TrieNode *child[26];
    	TrieNode() {
    		for(int i = 0; i < 26; i++) child[i] = NULL;
    	}
    };
    
    TrieNode* insert(TrieNode* root, string &key) {
    	TrieNode* cur = root;
    	int len = key.size();
    	for(int i = 0; i < len; i++) {
    		if(cur -> child[key[i] - 'a'] == NULL) {
    			TrieNode* newNode = new TrieNode();
    			cur -> child[key[i] - 'a'] = newNode;
    		}
    		cur = cur -> child[key[i]-'a'];
    	}
    	return root;
    }
    
    bool search(TrieNode* root, string &key) {
    	TrieNode* cur = root;
    	int len = key.size();
    	for(int i = 0; i < len; i++) {
    		if(cur -> child[key[i] - 'a'] == NULL)
    			return false;
    		cur = cur -> child[key[i] - 'a'];
    	}
    	return true;
    }
    
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        TrieNode* root = new TrieNode();
        for(string s : s1) {
            root = insert(root, s);
            string t = s;
            reverse(t.begin(), t.end());
            root = insert(root, t);
        }
        int ans = 0;
        for(string s : s2) {
            if(search(root, s)) ans++;
            else {
                string t = s;
                reverse(t.begin(), t.end());
                if(search(root, t)) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends