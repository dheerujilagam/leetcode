class Solution {
public:
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
    };

    TrieNode* insert(TrieNode* root, string &key){
        TrieNode* cur=root;
        int len=key.size();
        for(int i=0;i<len;i++){
            if(cur->child[key[i]-'a']==NULL){
                TrieNode* newNode=new TrieNode();
                cur->child[key[i]-'a']=newNode;
            }
            cur=cur->child[key[i]-'a'];
        }
        cur->isEnd=true;
        return root;
    }
    
    vector<string>res;
    void solve(TrieNode* root, TrieNode* cur, string &s, int i, int n, string k){
        //cout<<k<<" ";
        if(i==n){
            if(s.size()<=k.size() and cur->isEnd)
                res.push_back(k);
            return ;
        }
        if(cur->child[s[i]-'a']!=NULL){
            solve(root,cur->child[s[i]-'a'],s,i+1,n,k+s[i]);
            if(cur->isEnd) solve(root,root,s,i,n,k+" ");
            
        }
        else if(cur->isEnd) solve(root,root,s,i,n,k+" ");
        // else return ;
        //else solve(root,root,s,i+1,n,k);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root=new TrieNode();
        for(string s:wordDict){
            root=insert(root,s);
        }
        solve(root,root,s,0,s.size(),"");
        return res;
    }
};