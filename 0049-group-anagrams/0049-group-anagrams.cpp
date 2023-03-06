class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        
        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        
        for (auto p : mp) {
            result.push_back(p.second);
        }
        
        return result;
    }
};
