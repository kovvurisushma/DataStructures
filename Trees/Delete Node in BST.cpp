/*

Problem: Delete a node in BST
link: https://leetcode.com/problems/delete-node-in-a-bst/description/

*/

//Solution:

Node* DeleteBST(Node* root, int x) {
  if(!root) return root;
  if(root ->val > x) {
    root -> left = deleteBST(root -> left, x);
    return root;
  }
  if(root -> val < x) {
    root -> right = DeleteBST(root -> right, x);
    return root;
  }
  if(!root -> left && !root -> right) return NULL;
  if(!root -> left) return root -> right;
  if(!root -> right) return root -> left;
  int val = minEle(root -> right);
  root -> val = val;
  root -> right = DeleteBST(root -> right, val);
  return root;
}
