class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(nums, 0, seq, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& seq, vector<vector<int>>& res) {
        if (seq.size() > 1) res.push_back(seq);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (seq.empty() || nums[i] >= seq.back()) {
                used.insert(nums[i]);
                seq.push_back(nums[i]);
                dfs(nums, i + 1, seq, res);
                seq.pop_back();
            }
        }
    }
};
