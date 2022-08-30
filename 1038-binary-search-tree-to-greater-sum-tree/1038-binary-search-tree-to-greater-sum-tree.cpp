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
    TreeNode* bTg(TreeNode* root,int &sum){
        if(root==NULL)
            return NULL;
        bTg(root->right,sum);
        sum+=root->val;
        root->val=sum;
        bTg(root->left,sum);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        return bTg(root,sum);
    }
};