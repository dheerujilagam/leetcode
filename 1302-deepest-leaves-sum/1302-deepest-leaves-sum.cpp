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
    int sum=0;
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        else
            return max(height(root->left),height(root->right))+1;
    }
    void findSum(TreeNode* root, int l, int h){
        if(root==NULL)
            return ;
        if(l==h-1)
            sum+=root->val;
        findSum(root->left,l+1,h);
        findSum(root->right,l+1,h);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        findSum(root,0,h);
        return sum;
    }
};