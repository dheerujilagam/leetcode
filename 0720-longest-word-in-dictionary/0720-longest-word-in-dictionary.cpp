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
        int len=key.size(),t=0;
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
    
    bool search(TrieNode* root, string &key){
        TrieNode* cur=root;
        int len=key.size();
        for(int i=0;i<len;i++){
            if(cur==root || cur->isEnd)
                cur=cur->child[key[i]-'a'];
            else
                return false;
        }
	    return true;
    }
    
    string longestWord(vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(string it:words)
            root=insert(root,it);
        
        string res="";
        for(string it:words){
            if(search(root,it) && it.size()>=res.size()){
                if(it.size()==res.size())
                    res=min(it,res);
                else
                    res=it;
            }
        }
        return res;
    }
};