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
    int MaxPath(TreeNode* root, int& res){
        if(root){
            int l=MaxPath(root->left,res);
            int r=MaxPath(root->right,res);
            int mx=root->val+max(0,max(l,r));
            int Max=max(mx,root->val+l+r);
            res=max(Max,res);
            return mx;
        }
        return 0;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        MaxPath(root,res);
        return res;
    }
};