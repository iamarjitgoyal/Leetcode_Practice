class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        calculate_diameter(root, max_diameter);
        return max_diameter;
    }
    
private:
    int calculate_diameter(TreeNode* node, int& max_diameter) {
        if (!node) {
            return 0;
        }
        int left_height = calculate_diameter(node->left, max_diameter);
        int right_height = calculate_diameter(node->right, max_diameter);
        max_diameter = max(max_diameter, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
};
