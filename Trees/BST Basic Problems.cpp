/*

Problem: Insert Elements into BST
link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

*/

//Solution:

// Iterative
Node* insertIntoBST(Node* root, int val) {
  Node* nn = new Node(val);
  if(!root) return nn;
  Node* prev = NULL;
  while(root) {
    prev = root;
    if(root -> val > val) root = root -> left;
    else root = root -> right;
  }
  if(prev) {
    if(prev -> val > val) prev -> left = nn;
    else prev -> right = nn;
  }
  return nn;
}

// Recursive

TreeNode* insertIntoBST(TreeNode* root, int val) {
  TreeNode* nn = new TreeNode(val);
  if(!root) return nn;
  if(root -> val > val) root -> left =  insertIntoBST(root -> left, val);
  else root -> right = insertIntoBST(root -> right, val);
  return root;
}

/*
Problem: Search the given element in the given BST
link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
*/

//Solution:

//recursive
Node* searchBST(Node* root, int val) {
  if(!root) return NULL;
  else if(root -> val == val) return root;
  else if(root -> val > val) return searchBST(root -> left, val);
  else return searchBST(root -> right, val);
}

//Iterative
Node* searchBST(Node* root, int val) {
  if(!root) return NULL;
  while(root) {
    if(root -> val == val) return root;
    else if(root -> val > val) root = root -> left;
    else root = root -> right;
  }
  return NULL;
}
