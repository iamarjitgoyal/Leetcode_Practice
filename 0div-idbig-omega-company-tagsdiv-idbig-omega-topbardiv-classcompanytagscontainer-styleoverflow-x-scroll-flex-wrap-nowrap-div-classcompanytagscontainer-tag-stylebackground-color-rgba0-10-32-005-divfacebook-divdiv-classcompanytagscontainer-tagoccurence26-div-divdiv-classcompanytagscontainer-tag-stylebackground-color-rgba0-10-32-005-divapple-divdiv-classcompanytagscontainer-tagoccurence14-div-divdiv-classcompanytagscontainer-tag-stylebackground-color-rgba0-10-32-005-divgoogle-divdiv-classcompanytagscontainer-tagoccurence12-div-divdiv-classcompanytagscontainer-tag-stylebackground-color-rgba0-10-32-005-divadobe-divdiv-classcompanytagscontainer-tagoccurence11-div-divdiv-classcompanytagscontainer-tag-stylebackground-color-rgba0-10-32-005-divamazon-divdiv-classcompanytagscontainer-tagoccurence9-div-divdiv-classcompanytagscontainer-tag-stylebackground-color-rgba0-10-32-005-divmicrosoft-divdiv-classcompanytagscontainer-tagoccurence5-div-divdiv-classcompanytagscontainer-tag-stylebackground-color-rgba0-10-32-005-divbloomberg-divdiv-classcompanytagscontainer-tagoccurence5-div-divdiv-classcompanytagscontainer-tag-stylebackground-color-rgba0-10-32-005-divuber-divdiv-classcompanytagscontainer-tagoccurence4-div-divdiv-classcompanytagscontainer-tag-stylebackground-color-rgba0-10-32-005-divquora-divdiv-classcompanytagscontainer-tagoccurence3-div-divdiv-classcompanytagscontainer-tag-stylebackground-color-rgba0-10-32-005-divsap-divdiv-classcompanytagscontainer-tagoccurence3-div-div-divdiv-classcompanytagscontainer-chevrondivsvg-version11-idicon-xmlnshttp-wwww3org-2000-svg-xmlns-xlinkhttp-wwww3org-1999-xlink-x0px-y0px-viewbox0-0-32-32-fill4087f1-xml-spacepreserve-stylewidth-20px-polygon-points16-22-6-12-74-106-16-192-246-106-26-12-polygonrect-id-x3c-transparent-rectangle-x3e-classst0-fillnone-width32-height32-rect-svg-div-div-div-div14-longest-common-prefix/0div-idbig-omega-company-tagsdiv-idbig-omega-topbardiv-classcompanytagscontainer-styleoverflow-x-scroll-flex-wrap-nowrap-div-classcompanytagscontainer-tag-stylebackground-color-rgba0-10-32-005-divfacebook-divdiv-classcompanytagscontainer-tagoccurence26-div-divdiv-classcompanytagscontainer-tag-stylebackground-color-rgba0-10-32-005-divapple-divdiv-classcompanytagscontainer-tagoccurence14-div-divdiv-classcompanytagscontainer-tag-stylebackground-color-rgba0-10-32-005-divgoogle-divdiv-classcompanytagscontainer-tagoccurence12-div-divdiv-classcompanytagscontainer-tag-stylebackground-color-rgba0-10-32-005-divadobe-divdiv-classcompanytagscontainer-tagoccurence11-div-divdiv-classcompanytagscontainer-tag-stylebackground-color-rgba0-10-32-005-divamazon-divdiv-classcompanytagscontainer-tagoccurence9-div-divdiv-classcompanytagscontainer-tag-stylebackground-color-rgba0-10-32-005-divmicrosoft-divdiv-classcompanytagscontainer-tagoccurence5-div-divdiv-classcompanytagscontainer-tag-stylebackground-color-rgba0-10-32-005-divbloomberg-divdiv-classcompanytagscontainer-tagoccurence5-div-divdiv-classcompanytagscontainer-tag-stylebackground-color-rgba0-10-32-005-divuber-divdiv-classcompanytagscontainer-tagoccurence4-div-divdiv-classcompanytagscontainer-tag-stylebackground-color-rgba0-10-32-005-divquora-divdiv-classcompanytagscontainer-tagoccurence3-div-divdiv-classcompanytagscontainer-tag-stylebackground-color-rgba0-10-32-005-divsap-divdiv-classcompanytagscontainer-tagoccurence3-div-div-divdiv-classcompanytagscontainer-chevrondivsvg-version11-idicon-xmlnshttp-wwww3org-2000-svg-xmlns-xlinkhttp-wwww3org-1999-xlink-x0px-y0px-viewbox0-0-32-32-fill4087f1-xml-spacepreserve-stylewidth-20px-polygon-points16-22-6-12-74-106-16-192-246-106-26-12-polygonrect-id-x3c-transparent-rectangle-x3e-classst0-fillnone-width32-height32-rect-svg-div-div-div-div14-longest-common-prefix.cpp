
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        int minLength = INT_MAX;
        for (const string& str : strs) {
            minLength = min(minLength, static_cast<int>(str.length()));
        }
        
        for (int i = 0; i < minLength; ++i) {
            char currentChar = strs[0][i];
            for (const string& str : strs) {
                if (str[i] != currentChar) {
                    return str.substr(0, i);
                }
            }
        }
        
        return strs[0].substr(0, minLength);
    }
};