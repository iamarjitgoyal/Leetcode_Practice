class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int startColor = image[sr][sc];
        if (startColor == color) return image;
        dfs(image, sr, sc, startColor, color, m, n);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int startColor, int newColor, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != startColor) return;
        image[i][j] = newColor;
        dfs(image, i-1, j, startColor, newColor, m, n); 
        dfs(image, i+1, j, startColor, newColor, m, n); 
        dfs(image, i, j-1, startColor, newColor, m, n); 
        dfs(image, i, j+1, startColor, newColor, m, n); 
    }
};
