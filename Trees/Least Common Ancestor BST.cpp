/* 
Problem Statement: Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST
link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
*/

// Solution

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(!root) return root;
  if(root -> val < p -> val && root -> val < q -> val) return lowestCommonAncestor(root -> right, p, q);
  if(root -> val > p -> val && root -> val > q -> val) return lowestCommonAncestor(root -> left, p, q);
  else return root;
}
