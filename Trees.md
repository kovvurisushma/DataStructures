# Tree Data Structure

### Key Points

 - There will always be only one path between any 2 nodes
 - Height of the tree =  Height of the root node from the last level
 - Height(Tree) = Depth(Tree)
 - Depth(Tree) = Depth(deepest lead node)
 - level = depth + 1
 - Longesr path of the tree need not have to pas through the root, there can be a path from any where
 - N - array Tree : a tree having n number of nodes

### Binary Tree
- A tree having atmost 2 nodes
- Internal nodes: nodes which are not leaf nodes or root node.
- Complete Binary Tree - A binary tree in which all levels are filled except the last level and the last level is filled from left to right
- Full Binary Tree - A binary tree where every node has either 0 or 2 nodes.
- General structure of a binary tree:
  class Node {
    int data;
    Node left, right;
  }

  