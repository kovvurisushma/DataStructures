/*
Problem: Given a Binary Tree, check whether it is BST or not
link: https://leetcode.com/problems/validate-binary-search-tree/description/
*/

// Solution: 

int prev = INT_MIN;
bool isBST(Node* root, int prev) {
  if(!root) return true;
  bool l = isBST(root -> left);
  if(root -> val <= prev) return false;
  prev = root -> val;
  return l && isBST(root -> right);
}

// Approach2

bool isBST(Node* root, int lo, int hi) {
  if(!root) return true;
  if(root -> val <= lo) return false;
  if(root -> val >= hi) return false;
  return isBST(root -> left, lo, root -> val) && isBST(root -> right, root -> val, hi);
}
