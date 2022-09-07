/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,string>mp;
    void tra(TreeNode* r){
        if(r==NULL)
            return ;
        tra(r->left);
        tra(r->right);
        if(r->left==NULL and r->right==NULL)
            mp[r]='('+to_string(r->val)+')';
        else if(r->left==NULL and r->right!=NULL)
            mp[r]='('+to_string(r->val)+"()"+mp[r->right]+')';
        else if(r->left!=NULL and r->right==NULL)
            mp[r]='('+to_string(r->val)+mp[r->left]+')';
        else
            mp[r]='('+to_string(r->val)+mp[r->left]+mp[r->right]+')';
    }
    string tree2str(TreeNode* root) {
        tra(root);
        return mp[root].substr(1,mp[root].size()-2);
    }
};