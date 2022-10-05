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
    TreeNode* tra(TreeNode* r, int v, int d,int check){
        if(d==1){
            if(check==1)
                return new TreeNode(v,r,NULL);
            return new TreeNode(v,NULL,r);
        }
        if(r==NULL){
           return NULL; 
        }
        r->left=tra(r->left,v,d-1,1);
        r->right=tra(r->right,v,d-1,0);
        return r;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return tra(root,val,depth,1);
    }
};