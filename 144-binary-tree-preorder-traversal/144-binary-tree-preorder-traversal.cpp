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
    void pro(TreeNode* root, vector<int> &v){
        if(root!=NULL){
            v.push_back(root->val);
            pro(root->left,v);
            pro(root->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        pro(root,v);
        return v;
    }
};