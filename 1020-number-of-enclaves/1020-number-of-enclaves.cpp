class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        auto bfs = [&](int i, int j) {
            q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
                    continue;
                }
                grid[x][y] = 2;
                q.push({x+1, y});
                q.push({x-1, y});
                q.push({x, y+1});
                q.push({x, y-1});
            }
        };
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                bfs(0, j);
            }
            if (grid[m-1][j] == 1) {
                bfs(m-1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                bfs(i, 0);
            }
            if (grid[i][n-1] == 1) {
                bfs(i, n-1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
