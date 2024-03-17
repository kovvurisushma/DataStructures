/*
Problem Statement: Given a Binary Search Tree and a number x, find the floor of x in the given BST:
link: https://www.geeksforgeeks.org/floor-in-binary-search-tree-bst/
*/

//Solution

int floor(Node* root, int val) {
  if(!root) return -1;
  if(root -> val == val) return val;
  if(root -> val > val) return floor(root -> left, val);
  // TODO: complete this
}
