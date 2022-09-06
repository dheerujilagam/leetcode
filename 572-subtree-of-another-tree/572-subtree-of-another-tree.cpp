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
    bool flag=false;
    bool trav(TreeNode* r, TreeNode* s){
        if(s==NULL and r==NULL)
            return true;
        if((s!=NULL and r==NULL) or (s==NULL and r!=NULL))
            return false;
        if((r->val==s->val) and trav(r->left,s->left) and trav(r->right,s->right))
                return true;
        return false;
    }
    void tra(TreeNode* r, TreeNode* s){
        if(r){
            tra(r->left,s);
            bool x=trav(r,s);
            if(x)
                flag=true;
            tra(r->right,s);
        }
    }
    bool isSubtree(TreeNode* r, TreeNode* s) {
        tra(r,s);
        return flag;
    }
};