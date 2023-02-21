class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCounts;
        for (char c : magazine) {
            charCounts[c]++;
        }
        for (char c : ransomNote) {
            if (charCounts[c] > 0) {
                charCounts[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
