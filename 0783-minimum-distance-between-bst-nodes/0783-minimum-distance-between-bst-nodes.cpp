/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX; // Initialize minimum difference with maximum integer value
        int prevVal = -1; // Initialize previous value to an invalid value
        
        inorderTraversal(root, prevVal, minDiff); // Traverse the tree in inorder and update minimum difference
        
        return minDiff;
    }
    
    void inorderTraversal(TreeNode* root, int& prevVal, int& minDiff) {
        if (root == nullptr) {
            return;
        }
        
        inorderTraversal(root->left, prevVal, minDiff); // Traverse left subtree
        
        if (prevVal != -1) { // Calculate minimum difference
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val; // Update previous value
        
        inorderTraversal(root->right, prevVal, minDiff); // Traverse right subtree
    }
};
