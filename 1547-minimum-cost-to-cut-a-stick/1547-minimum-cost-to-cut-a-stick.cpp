class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size(); 

        unordered_map<int, unordered_map<int, int>> memo;
        
        return dp(0, m - 1, cuts, memo);
    }
    
private:
    int dp(int i, int j, const vector<int>& cuts, unordered_map<int, unordered_map<int, int>>& memo) {
        if (j - i < 2) {
            return 0;
        }
        
        if (memo.count(i) && memo[i].count(j)) {
            return memo[i][j];
        }
        
        int cost = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            cost = min(cost, dp(i, k, cuts, memo) + dp(k, j, cuts, memo) + cuts[j] - cuts[i]);
        }
        
        memo[i][j] = cost;
        
        return cost;
    }
};