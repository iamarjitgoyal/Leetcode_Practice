class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        vector<vector<int>> colorCount(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                colorCount[i][colors[i] - 'a'] = 1;
            }
        }
        int longestPath = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                for (int c = 0; c < 26; c++) {
                    colorCount[v][c] = max(colorCount[v][c], colorCount[u][c] + (colors[v] - 'a' == c));
                }
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
            int maxColorCount = 0;
            for (int c = 0; c < 26; c++) {
                maxColorCount = max(maxColorCount, colorCount[u][c]);
            }
            longestPath = max(longestPath, maxColorCount);
        }
        for (int i = 0; i < n; i++) {
            if (inDegree[i] > 0) {
                return -1;
            }
        }
        return longestPath;
    }
};
