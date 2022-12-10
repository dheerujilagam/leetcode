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
    long mod=1000000007,tot,ans=0;
    int totalSum(TreeNode* root){
        if(root==NULL) return 0;
        return totalSum(root->left)+totalSum(root->right)+root->val;
    }
    int prodMax(TreeNode* root){
        if(root){
            long sub=root->val+prodMax(root->left)+prodMax(root->right);
            ans=max(ans,sub*abs(tot-sub));
            return sub;
        }
        return 0;
    }
    int maxProduct(TreeNode* root) {
        tot=totalSum(root);
        prodMax(root);
        return ans%mod;
    }
};