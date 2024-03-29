/*
Problem Statement: Construct Binary Tree from given In order and Pre order traversal
link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
*/

//Solution 

    int indx = 0;
    unordered_map<int, int> mp;
    TreeNode* constructTree(vector<int> &preorder, vector<int>& inorder, int lo, int hi) {
        if(lo > hi || indx > preorder.size() - 1) return NULL;
        int cur = preorder[indx++];
        int inorderIndx = mp[cur];
        cout << cur << " ";
        TreeNode* nn = new TreeNode(cur);
        nn -> left = constructTree(preorder, inorder, lo, inorderIndx - 1);
        nn -> right = constructTree(preorder, inorder, inorderIndx + 1, hi);
        return nn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
       return constructTree(preorder, inorder, 0, preorder.size()); 
    }

/*
Problem Statement: Print Post order traversal from given inorder and preorder traversal
link: https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
*/

//Solution

int indx = 0;
unordered_map<int, int> mp;
void printPos(int in[], int pre[], int lo, int hi) {
    if(lo > hi) return;
    int cur = pre[indx++];
    int inIndx = mp[cur];
    printPos(in, pre, lo, inIndx - 1);
    printPos(in, pre, inIndx + 1, hi);
    cout << cur << " ";
}


void printPostOrder(int in[], int pre[], int n)
{
    mp.clear();
    indx = 0;
    for(int i = 0 ; i < n; i++) mp[in[i]] = i;
    printPos(in, pre, 0, n - 1);
}
