/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode tra(TreeNode r, int v, int d, int check){
        if(d==1){
            if(check==1)
                return new TreeNode(v,r,null);
            return new TreeNode(v,null,r);
        }
        if(r==null)
            return null;
        r.left=tra(r.left,v,d-1,1);
        r.right=tra(r.right,v,d-1,0);
        return r;
    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        return tra(root,val,depth,1);
    }
}