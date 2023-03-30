class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) {
            return false;
        }
        if (n == 0) {
            return true;
        }
        if (s1 == s2) {
            return true;
        }
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (k == 1) {
                        dp[i][j][1] = (s1[i] == s2[j]);
                    } else {
                        for (int p = 1; p < k && !dp[i][j][k]; p++) {
                            dp[i][j][k] = dp[i][j][k] || ((dp[i][j + k - p][p] && dp[i + p][j][k - p]) || (dp[i][j][p] && dp[i + p][j + p][k - p]));
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
