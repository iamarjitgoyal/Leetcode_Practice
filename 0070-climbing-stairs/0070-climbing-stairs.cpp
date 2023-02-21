class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        vector<vector<int>> base = {{1, 1}, {1, 0}};
        vector<vector<int>> res = matrix_pow(base, n - 1);
        return res[0][0] + res[0][1];
    }
    
    vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int m = A.size();
        int n = A[0].size();
        int p = B[0].size();
        vector<vector<int>> C(m, vector<int>(p));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                int sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
    
    vector<vector<int>> matrix_pow(const vector<vector<int>>& A, int n) {
        if (n == 0) {
            return {{1, 0}, {0, 1}};
        }
        vector<vector<int>> half = matrix_pow(A, n/2);
        vector<vector<int>> res = matrix_multiply(half, half);
        if (n % 2 == 1) {
            res = matrix_multiply(res, A);
        }
        return res;
    }
};
