class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n);
        return dfs(0, adj, visited, hasApple);
    }
    
    int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& hasApple) {
        visited[u] = true;
        int res = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                int sub = dfs(v, adj, visited, hasApple);
                if (sub != 0 || hasApple[v]) {
                    res += sub + 2;
                }
            }
        }
        return res;
    }
};
