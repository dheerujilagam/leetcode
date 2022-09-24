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
    List<List<Integer>>f=new ArrayList<>();
    public void check(TreeNode r, int targetsum, List<Integer>t){
        if(r==null) return ;
        t.add(r.val);
        if(targetsum==r.val && r.left==null && r.right==null){
            if(!t.isEmpty())
                f.add(new ArrayList<>(t));
        }
        check(r.left,targetsum-r.val,t);
        check(r.right,targetsum-r.val,t);
        t.remove(t.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer>t=new ArrayList<>();
        check(root,targetSum,t);
        return f;
    }
}