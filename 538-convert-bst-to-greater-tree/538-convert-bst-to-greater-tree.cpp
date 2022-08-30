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
    vector<int>v;
    int sum;
    void trav(TreeNode* root){
        if(root==NULL)
            return ;
        auto it=lower_bound(v.begin(),v.end(),root->val)-v.begin();
        v.insert(v.begin()+it,root->val);
        trav(root->left);
        trav(root->right);
    }
    void assign(TreeNode* root){
        if(root==NULL)
            return ;
        auto it=lower_bound(v.begin(),v.end(),root->val)-v.begin();
        root->val=sum-accumulate(v.begin(),v.begin()+it,0);
        assign(root->left);
        assign(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        trav(root);
        sum=accumulate(v.begin(),v.end(),0);
        assign(root);
        for(auto i:v)
            cout<<i<<" ";
        return root;
    }
};