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
    int res=Integer.MIN_VALUE;
    public int MaxPath(TreeNode root){
        if(root==null) return 0;
        int l=MaxPath(root.left);
        int r=MaxPath(root.right);
        int t=root.val+Math.max(0,Math.max(l,r));
        int mx=Math.max(t,root.val+l+r);
        res=Math.max(mx,res);
        return t;
    }
    public int maxPathSum(TreeNode root) {
        MaxPath(root);
        return res;
    }
}