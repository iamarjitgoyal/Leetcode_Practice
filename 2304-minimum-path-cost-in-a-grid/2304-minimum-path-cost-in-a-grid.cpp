class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
                }
            }
        }
        
        int minCost = INT_MAX;
        for (int j = 0; j < n; j++) {
            minCost = min(minCost, dp[m-1][j]);
        }
        
        return minCost;
    }
};
