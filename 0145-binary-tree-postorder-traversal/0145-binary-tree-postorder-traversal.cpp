class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* prev = NULL;
        
        while (root != NULL || !s.empty()) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if(root->right == NULL || root->right == prev){
                result.push_back(root->val);
                s.pop();
                prev = root;
                root = NULL;
            } 
            else{
                root = root->right;
            }
        }
        
        return result;
    }
};
