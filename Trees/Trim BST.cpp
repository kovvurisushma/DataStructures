/*
Problem Statement: Trim the given BST, such that all the nodes will be in the given range[a,b]
link: https://leetcode.com/problems/trim-a-binary-search-tree/
*/

// Solution

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root -> val < low) return trimBST(root -> right, low, high);
        if(root -> val > high) return trimBST(root -> left, low, high);
        root -> left = trimBST(root -> left, low, high);
        root -> right = trimBST(root -> right, low, high);
        return root;
    }
