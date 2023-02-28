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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> subtreeCount;
        dfs(root, subtreeCount, result);
        return result;
    }
    
private:
    string dfs(TreeNode* node, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& result) {
        if (!node) {
            return "#";
        }
        string subtree = to_string(node->val) + "," + dfs(node->left, subtreeCount, result) + "," + dfs(node->right, subtreeCount, result);
        if (subtreeCount[subtree] == 1) {
            result.push_back(node);
        }
        ++subtreeCount[subtree];
        return subtree;
    }
};
