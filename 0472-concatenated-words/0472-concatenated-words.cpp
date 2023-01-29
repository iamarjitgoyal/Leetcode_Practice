class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set;
        for (string word : words) {
            set.insert(word);
        }
        vector<string> result;
        for (string word : words) {
            set.erase(word);
            int n = word.length();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && set.count(word.substr(j, i - j))) {
                        dp[i] = 1;
                        break;
                    }
                }
                if (i == n && dp[i]) {
                    result.push_back(word);
                }
            }
            set.insert(word);
        }
        return result;
    }
};