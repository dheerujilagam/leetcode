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
    int height(TreeNode* r){
        if(r==NULL)
            return 0;
        return max(height(r->left),height(r->right))+1;
    }
    bool tra(TreeNode* r){
        if(r==NULL)
            return true;
        int i=height(r->left),j=height(r->right);
        if(abs(i-j)<=1 && tra(r->left) && tra(r->right))
            return true;
        else
            return false;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return tra(root);
    }
};