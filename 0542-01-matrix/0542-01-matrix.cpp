class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int newRow = curr.first + dir.first;
                int newCol = curr.second + dir.second;
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (distance[newRow][newCol] > distance[curr.first][curr.second] + 1) {
                        distance[newRow][newCol] = distance[curr.first][curr.second] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return distance;
    }
};
