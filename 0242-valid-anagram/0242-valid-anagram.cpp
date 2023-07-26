#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> frequency(128, 0);
        for (char c : s) {
            frequency[c]++;
        }
        for (char c : t) {
            frequency[c]--;
        }
        for (int count : frequency) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
