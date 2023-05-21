class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        bool found = false;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            if (found) break;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        
        
        int steps = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int newRow = row + dirs[k];
                    int newCol = col + dirs[k + 1];
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                        if (grid[newRow][newCol] == 1) {
                            return steps;
                        } else if (grid[newRow][newCol] == 0) {
                            grid[newRow][newCol] = -1;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int row, int col, queue<pair<int, int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 1) {
            return;
        }
        
        grid[row][col] = -1;
        q.push({row, col});
        
        dfs(grid, row - 1, col, q);
        dfs(grid, row + 1, col, q);
        dfs(grid, row, col - 1, q);
        dfs(grid, row, col + 1, q);
    }
};
