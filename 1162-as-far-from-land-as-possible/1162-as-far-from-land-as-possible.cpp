class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = -1;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty() || q.size() == n * m) {
            return res;
        }
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (auto dir : dirs) {
                int a = x + dir.first, b = y + dir.second;
                if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 0) {
                    grid[a][b] = grid[x][y] + 1;
                    res = max(res, grid[a][b] - 1);
                    q.push({a, b});
                }
            }
        }
        return res;
    }
};
