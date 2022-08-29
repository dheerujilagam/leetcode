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
    int h;
    vector<int>v;
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        else
            return max(height(root->left),height(root->right))+1;
    }
    void left(TreeNode *root, int h){
        if(root){
            if(h==1){ 
                v.push_back(root->val);
            }
            else{
                left(root->left,h-1);
                left(root->right,h-1);
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        h=height(root);
        cout<<h<<"\n";
        left(root,h);
        return v[0];
    }
};