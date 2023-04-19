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
    int longestZigZag(TreeNode* root) {
        int longest = 0;
        if (root == nullptr) {
            return longest;
        }
        dfs(root->left, true, 1, longest);
        dfs(root->right, false, 1, longest);
        return longest;
    }
    
    void dfs(TreeNode* node, bool isLeft, int length, int& longest) {
        if (node == nullptr) {
            longest = std::max(longest, length - 1);
            return;
        }
        if (isLeft) {
            dfs(node->right, false, length + 1, longest);
            dfs(node->left, true, 1, longest);
        } else {
            dfs(node->left, true, length + 1, longest);
            dfs(node->right, false, 1, longest);
        }
    }
};
