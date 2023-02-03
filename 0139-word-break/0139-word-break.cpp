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
        
   bool search(TrieNode* root, string key){
        TrieNode* cur=root;
        int len=key.size();
        for(int i=0;i<len;i++){
            if(cur->child[key[i]-'a']==NULL)
                return false;
            cur=cur->child[key[i]-'a'];
        }
        return cur->isEnd;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root=new TrieNode();
        for(string it:wordDict){
            root=insert(root,it);
        }
        int n=s.size();
        vector<bool>dp(n+1,0);;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && search(root,s.substr(j,i-j)))
                    dp[i]=1;
            }
        }
        return dp[n];
    }
};