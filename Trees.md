# Tree Data Structure

### Key Points

 - There will always be only one path between any 2 nodes
 - Height of the tree =  Height of the root node from the last level
 - Height(Tree) = Depth(Tree)
 - Depth(Tree) = Depth(deepest lead node)
 - level = depth + 1
 - The longest path of the tree need not have passed through the root, there can be a path from anywhere
 - N - array Tree: a tree having n number of nodes

### Binary Tree
- A tree having at most 2 nodes
- Internal nodes: nodes that are not leaf nodes or root nodes.
- Complete Binary Tree - A binary tree in which all levels are filled except the last level and the last level is filled from left to right
- Full Binary Tree - A binary tree where every node has either 0 or 2 nodes.
- Horizontal Distance (HD): is the distance of a node from the root node. The HD of the root node is zero. Any node that falls in the vertical line after the root node line will be positive, and any node that falls in the vertical line to the left of the root node will be negative.
- General structure of a binary tree:
  class Node {
    int data;
    Node left, right;
  }

### Binary Search Tree
- all(left nodes) < root < all(right nodes)

  
