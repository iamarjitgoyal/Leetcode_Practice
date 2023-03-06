class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for (string s : strs) {
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            string hash = "";
            for (int i = 0; i < 26; i++) {
                hash += "#" + to_string(count[i]);
            }
            mp[hash].push_back(s);
        }
        for (auto p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};
