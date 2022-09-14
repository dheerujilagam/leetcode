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
    int cnt=0;
    void check(TreeNode* r, vector<int>v){
        if(r==NULL)
            return ;
        v[r->val]++;
        if(r->left==NULL and r->right==NULL){
            int c=0;
            for(auto it:v){
                if(it%2==1)
                    c++;
            }
            if(c<=1)
                cnt++;
        }
        check(r->left,v);
        check(r->right,v);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        check(root,v);
        return cnt;
    }
};