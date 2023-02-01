class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int len = min(m - i + 1, n - j + 1);
                int l = 0, r = len;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    int sum = prefixSum[i + mid - 1][j + mid - 1] - prefixSum[i - 1][j + mid - 1] - prefixSum[i + mid - 1][j - 1] + prefixSum[i - 1][j - 1];
                    if (sum <= threshold) l = mid;
                    else r = mid - 1;
                }
                res = max(res, l);
            }
        }
        return res;
    }
};
