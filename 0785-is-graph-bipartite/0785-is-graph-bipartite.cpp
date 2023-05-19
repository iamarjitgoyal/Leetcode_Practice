class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0); // 0: uncolored, 1: color A, -1: color B
        
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                if (!dfs(graph, i, 1, colors))
                    return false;
            }
        }
        
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int node, int color, vector<int>& colors) {
        colors[node] = color;
        
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == color)
                return false;
            
            if (colors[neighbor] == 0 && !dfs(graph, neighbor, -color, colors))
                return false;
        }
        
        return true;
    }
};
