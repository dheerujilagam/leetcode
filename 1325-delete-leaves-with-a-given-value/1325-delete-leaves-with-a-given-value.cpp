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
    TreeNode* tra(TreeNode* r, int t){
        if(r!=NULL){
            r->left=tra(r->left,t);
            r->right=tra(r->right,t);
            if(r->left==NULL and r->right==NULL and r->val==t){
                return NULL;
            }
            else
                return r;
        }
        return NULL;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        return tra(root,t);
    }
};