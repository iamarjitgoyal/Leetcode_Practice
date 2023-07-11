class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    
    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        
        if (!parent)
            parent = node;
        else
            parentMap[node] = parent;
        
        dfs(node->left, node);
        dfs(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> queue;
        set<TreeNode*> visited;
        
        dfs(root, nullptr);
        queue.push(target);
        
        int distance = 0;
        vector<int> result;
        
        while (!queue.empty()) {
            int levelSize = queue.size();
            
            if (distance > k)
                break;
            
            while (levelSize--) {
                TreeNode* node = queue.front();
                queue.pop();
                
                if (node->left && !visited.count(node->left)) {
                    queue.push(node->left);
                    visited.insert(node->left);
                }
                
                if (node->right && !visited.count(node->right)) {
                    queue.push(node->right);
                    visited.insert(node->right);
                }
                
                if (parentMap.count(node) && !visited.count(parentMap[node])) {
                    queue.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
                
                visited.insert(node);
                
                if (distance == k) {
                    result.push_back(node->val);
                }
            }
            
            distance++;
        }
        
        return result;
    }
};
