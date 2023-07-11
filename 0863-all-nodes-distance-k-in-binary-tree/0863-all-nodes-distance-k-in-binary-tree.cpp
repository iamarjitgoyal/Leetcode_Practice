class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    
    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        parentMap[node] = parent;
        
        dfs(node->left, node);
        dfs(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        
        queue<TreeNode*> queue;
        queue.push(target);
        
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        int distance = 0;
        vector<int> result;
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            
            if (distance == k) {
                while (levelSize--) {
                    TreeNode* node = queue.front();
                    queue.pop();
                    result.push_back(node->val);
                }
                return result;
            }
            
            while (levelSize--) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if (node->left && visited.insert(node->left).second)
                    queue.push(node->left);
                
                if (node->right && visited.insert(node->right).second)
                    queue.push(node->right);
                
                TreeNode* parent = parentMap[node];
                
                if (parent && visited.insert(parent).second)
                    queue.push(parent);
            }
            
            distance++;
        }
        
        return result;
    }
};
