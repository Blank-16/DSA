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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        if (root == null)
            return result;
        TreeNode cur = root;
        while (cur != null) {

            if (cur.right == null) {
                result.add(cur.val);
                cur = cur.left;
            } else {

                TreeNode inorderSuc = cur.right;
                while (inorderSuc.left != null && inorderSuc.left != cur) {
                    inorderSuc = inorderSuc.left;
                }
                if (inorderSuc.left == null) {
                    result.add(cur.val);
                    inorderSuc.left = cur;
                    cur = cur.right;
                } else {
                    //result.add(cur.val);
                    inorderSuc.left = null;
                    cur = cur.left;
                }
            }
        }
        Collections.reverse(result);
        return result;
    }
}
