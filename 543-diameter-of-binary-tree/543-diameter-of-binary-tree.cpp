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
    int height(TreeNode *root){
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameter(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        return max(lh+rh,max(ld,rd));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};