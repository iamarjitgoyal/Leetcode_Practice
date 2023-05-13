class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int numZeros, int numOnes) {
        vector<int> dp(high + 1, -1);
        return countGoodStringsHelper(0, low, high, dp, numZeros, numOnes);
    }

    int countGoodStringsHelper(int length, int low, int high, vector<int>& dp, int numZeros, int numOnes) {
        if (length > high) {
            return 0;
        }
        if (dp[length] != -1) {
            return dp[length];
        }
        int ans = 0;
        if (length >= low && length <= high) {
            ans = 1;
        }
        ans = (ans + countGoodStringsHelper(length + numZeros, low, high, dp, numZeros, numOnes)) % MOD;
        ans = (ans + countGoodStringsHelper(length + numOnes, low, high, dp, numZeros, numOnes)) % MOD;
        dp[length] = ans;
        return ans;
    }
};
