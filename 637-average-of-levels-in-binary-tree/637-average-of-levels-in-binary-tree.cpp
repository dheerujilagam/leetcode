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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long t=0;
            long n=q.size();
            for(long i=0;i<n;i++){
                TreeNode* temp=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                t+=temp->val;
                q.pop();
            }
            res.push_back((double)t/n);
        }
        return res;
    }
};