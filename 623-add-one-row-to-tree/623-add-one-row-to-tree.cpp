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
    TreeNode* tra(TreeNode* r, int v, int d,int l_end, int r_end){
        if(d==1){
            if(l_end==1)
                return new TreeNode(v,r,NULL);
            if(r_end==1)
                return new TreeNode(v,NULL,r);
        }
        if(r==NULL){
           return NULL; 
        }
        r->left=tra(r->left,v,d-1,1,0);
        r->right=tra(r->right,v,d-1,0,1);
        return r;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return tra(root,val,depth,1,1);
    }
};