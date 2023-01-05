class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> res;
            vector<int> combination;
            dfs(k, n, 1, combination, res);
            return res;
        }
    void dfs(int k, int n, int start, vector<int>& combination, vector<vector<int>>& res) {
        if (k == 0 && n == 0) {
            res.push_back(combination);
            return;
        }
        if (k == 0 || n == 0) return;
        for (int i = start; i <= 9; i++) {
            combination.push_back(i);
            dfs(k - 1, n - i, i + 1, combination, res);
            combination.pop_back();
        }
    }
};