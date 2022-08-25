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
    vector<int>ans;
    void find(TreeNode* root){
        if(root==NULL) return ;
        ans.push_back(root->val);
        find(root->left);
        find(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        find(root);
        sort(ans.begin(),ans.end());
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k)
                return true;
            else if(ans[i]+ans[j]>k)
                j--;
            else
                i++;
        }
        return false;
    }
};