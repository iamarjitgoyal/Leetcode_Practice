class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCounts[26] = {0};
        for (char c : magazine) {
            charCounts[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (charCounts[c - 'a'] > 0) {
                charCounts[c - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};
