/*
Problem: Print Level Order Traversal of given Binary Tree
link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

// Solution:

void levelOrderTraversal(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node* cur = q.front();
    q.pop();
    cout << cur -> val << " ";
    if(cur -> left) q.push(cur -> left);  
    if(cur -> right) q.push(cur -> right);
  }
  return;
}

/*
- In this approach all the nodes are printed in single line with space seperated

Approach in case we have to differentiate levels
- use specifier, i.e., null
- add null after adding root element
- and while traversing through the queue, check if the poped element is null, if its null then pop null from queue and add it at the end;
- this may result in infinite loop, if we add null without checking if q is empty or not
- so check if queue is empty or not, if it is not empty then add the null
*/

// Solution: 

void levelOrderTraversal(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    Node* cur = q.front();
    q.pop();
    if(cur == NULL ) {
        cout << "\n";
        if(!q.empty()) q.push(NULL);
    } else { 
        cout << cur -> val << " ";
        if(cur -> left) q.push(cur -> left);
        if(cur -> right) q.push(cur -> right);
    }
  }
} 
