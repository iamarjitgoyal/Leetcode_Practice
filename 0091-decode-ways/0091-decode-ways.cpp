// class Solution {
// public:
//     int numDecodings(string s) {
//         return dfs(s, 0);
//     }
// private:
//     int dfs(string s, int start) {
//         if (start == s.length()) {
//             return 1; //base case, if we have reached end of the string, return 1
//         }
//         if (s[start] == '0') {
//             return 0; //if the current digit is 0, return 0
//         }
//         int ans = dfs(s, start + 1);
//         if (start < s.length() - 1 && (s[start] == '1' || (s[start] == '2' && s[start + 1] <= '6'))) {
//             ans += dfs(s, start + 2);
//         }
//         return ans;
//     }
// };
 



// Above was recursive approach, TLE occured, so using Dynamic Programming Now




class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0; // if the string is empty or the first digit is 0, return 0
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1; // base case
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
