class Solution {
public:
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return false;
        if(grid[i][j]==1) return true;
        grid[i][j] = 1;
        bool up = isClosed(grid,i-1,j);
        bool down = isClosed(grid,i+1,j);
        bool left = isClosed(grid,i,j-1);
        bool right = isClosed(grid,i,j+1);
        return up && down && left && right;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 && isClosed(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
