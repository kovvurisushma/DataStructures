/*
Problem: Given a Binary tree, print the pre-order traversal
link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

// Solution:

void preorderTraversal(Node* root) {
  if(!root) return;
  print(root -> data);
  preorderTraversal(root -> left);
  preorderTraversal(root -> right);
}

/*

Problem: Given a Binary Tree, print the post-order traversal
link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

*/

// Solution:

void postOrderTraversal(Node* root) {
  if(!root) return;
  postOrderTraversal(root -> left);
  postOrderTraversal(root -> right);
  print(root);
}

// Problem: Given a Binary Tree, Print inorder traversal
// link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// Solution:

void inorderTraversal(Node* root) {
  if(!root) return;
  inorderTraversal(root -> left);
  print(root -> val);
  inorderTraversal(root -> right);
}

// Problem: Given a Binary Tree, count number of nodes inside it
// link: https://leetcode.com/problems/count-complete-tree-nodes/description/

// Solution:

int count(Node* root) {
  if(!root) return 0;
  return count(root -> left) + count(root -> right) + 1;
}

// Problem: return sum of all nodes of a binary tree
// link: https://www.geeksforgeeks.org/sum-nodes-binary-tree/

// Solution:

int sumOfAllNodes(Node* root) {
  if(!root) return;
  return sumOfAllNodes(root -> left) + sumOfAllNodes(root -> right) + root -> val;
}


// Problem: return max and min node in the given binary tree
// link: https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/

// Solution:

int findMax(Node *root) {
  if(!root) return INT_MIN;
  return max(findMax(root -> left), min(findMax(root -> right), root -> data));
}
int findMin(Node *root) {
  if(!root) return INT_MAX;
  return min(findMin(root -> left), min(findMin(root -> right), root -> data));
}

// Problem: return the height of the given binary tree
// link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Solution:

int maxDepth(TreeNode* root) {
  if(!root) return 0;
  return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}

// Problem: return the horizontal distance of given binary tree
// link:

// Solution:

int horizontalDistance(Node* root, int hd) {
  if(!root) return hd;
  root.hd = hd;
  horizontalDistance(root -> left, hd - 1);
  horizontalDistance(root -> right, hd + 1);
}

// Problem: convert given binary tree into its mirror image
// link: https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

// Solution:

void mirror(Node* node) {
  if(!root) return;
  mirror(node -> left);
  mirror(node -> right);
  swap(node -> left, node -> right);
}
