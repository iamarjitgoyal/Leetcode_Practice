class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
        backtrack(result, candidates, currentCombination, 0, target);
        
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& currentCombination, int start, int target) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                currentCombination.push_back(candidates[i]);
                backtrack(result, candidates, currentCombination, i, target - candidates[i]);
                
                currentCombination.pop_back();
            }
        }
    }
};
