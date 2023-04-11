class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        int minutes = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty() && freshOranges > 0){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> curr = q.front();
                q.pop();
                for(auto dir : directions){
                    int x = curr.first + dir[0];
                    int y = curr.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        freshOranges--;
                        q.push({x, y});
                    }
                }
            }
            minutes++;
        }
        
        return (freshOranges == 0) ? minutes : -1;
    }
};
