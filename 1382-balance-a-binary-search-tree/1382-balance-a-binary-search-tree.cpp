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
    vector<TreeNode*>v;
    void traverse(TreeNode* root){
        if(root==NULL)
            return ;
        traverse(root->left);
        v.push_back(root);
        traverse(root->right);
    }
    TreeNode* insert(int s, int e){
        if(s>e)
            return NULL;
        int m=(s+e)/2;
        TreeNode* root=v[m];
        root->left=insert(s,m-1);
        root->right=insert(m+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        TreeNode* newroot=NULL;
        return insert(0,v.size()-1);
    }
};