class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, colors)) {
                result.push_back(i);
            }
        }

        return result;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors) {
        if (colors[node] != 0) {
            return colors[node] == 2;
        }

        colors[node] = 1;

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, colors)) {
                return false;
            }
        }

        colors[node] = 2;
        return true;
    }
};
