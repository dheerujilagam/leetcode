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
    vector<vector<int>>paths;
    vector<int>t;
    void check(TreeNode* root, int targetSum, vector<int> t){
        if(root==NULL) return ;
        if(!root->left and !root->right){
            if(root->val==targetSum){
                t.push_back(root->val);
                paths.push_back(t);
            }
        }
        t.push_back(root->val);
        check(root->left,targetSum-root->val,t);
        check(root->right,targetSum-root->val,t);
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        check(root, targetSum, t);
        return paths;
    }
};