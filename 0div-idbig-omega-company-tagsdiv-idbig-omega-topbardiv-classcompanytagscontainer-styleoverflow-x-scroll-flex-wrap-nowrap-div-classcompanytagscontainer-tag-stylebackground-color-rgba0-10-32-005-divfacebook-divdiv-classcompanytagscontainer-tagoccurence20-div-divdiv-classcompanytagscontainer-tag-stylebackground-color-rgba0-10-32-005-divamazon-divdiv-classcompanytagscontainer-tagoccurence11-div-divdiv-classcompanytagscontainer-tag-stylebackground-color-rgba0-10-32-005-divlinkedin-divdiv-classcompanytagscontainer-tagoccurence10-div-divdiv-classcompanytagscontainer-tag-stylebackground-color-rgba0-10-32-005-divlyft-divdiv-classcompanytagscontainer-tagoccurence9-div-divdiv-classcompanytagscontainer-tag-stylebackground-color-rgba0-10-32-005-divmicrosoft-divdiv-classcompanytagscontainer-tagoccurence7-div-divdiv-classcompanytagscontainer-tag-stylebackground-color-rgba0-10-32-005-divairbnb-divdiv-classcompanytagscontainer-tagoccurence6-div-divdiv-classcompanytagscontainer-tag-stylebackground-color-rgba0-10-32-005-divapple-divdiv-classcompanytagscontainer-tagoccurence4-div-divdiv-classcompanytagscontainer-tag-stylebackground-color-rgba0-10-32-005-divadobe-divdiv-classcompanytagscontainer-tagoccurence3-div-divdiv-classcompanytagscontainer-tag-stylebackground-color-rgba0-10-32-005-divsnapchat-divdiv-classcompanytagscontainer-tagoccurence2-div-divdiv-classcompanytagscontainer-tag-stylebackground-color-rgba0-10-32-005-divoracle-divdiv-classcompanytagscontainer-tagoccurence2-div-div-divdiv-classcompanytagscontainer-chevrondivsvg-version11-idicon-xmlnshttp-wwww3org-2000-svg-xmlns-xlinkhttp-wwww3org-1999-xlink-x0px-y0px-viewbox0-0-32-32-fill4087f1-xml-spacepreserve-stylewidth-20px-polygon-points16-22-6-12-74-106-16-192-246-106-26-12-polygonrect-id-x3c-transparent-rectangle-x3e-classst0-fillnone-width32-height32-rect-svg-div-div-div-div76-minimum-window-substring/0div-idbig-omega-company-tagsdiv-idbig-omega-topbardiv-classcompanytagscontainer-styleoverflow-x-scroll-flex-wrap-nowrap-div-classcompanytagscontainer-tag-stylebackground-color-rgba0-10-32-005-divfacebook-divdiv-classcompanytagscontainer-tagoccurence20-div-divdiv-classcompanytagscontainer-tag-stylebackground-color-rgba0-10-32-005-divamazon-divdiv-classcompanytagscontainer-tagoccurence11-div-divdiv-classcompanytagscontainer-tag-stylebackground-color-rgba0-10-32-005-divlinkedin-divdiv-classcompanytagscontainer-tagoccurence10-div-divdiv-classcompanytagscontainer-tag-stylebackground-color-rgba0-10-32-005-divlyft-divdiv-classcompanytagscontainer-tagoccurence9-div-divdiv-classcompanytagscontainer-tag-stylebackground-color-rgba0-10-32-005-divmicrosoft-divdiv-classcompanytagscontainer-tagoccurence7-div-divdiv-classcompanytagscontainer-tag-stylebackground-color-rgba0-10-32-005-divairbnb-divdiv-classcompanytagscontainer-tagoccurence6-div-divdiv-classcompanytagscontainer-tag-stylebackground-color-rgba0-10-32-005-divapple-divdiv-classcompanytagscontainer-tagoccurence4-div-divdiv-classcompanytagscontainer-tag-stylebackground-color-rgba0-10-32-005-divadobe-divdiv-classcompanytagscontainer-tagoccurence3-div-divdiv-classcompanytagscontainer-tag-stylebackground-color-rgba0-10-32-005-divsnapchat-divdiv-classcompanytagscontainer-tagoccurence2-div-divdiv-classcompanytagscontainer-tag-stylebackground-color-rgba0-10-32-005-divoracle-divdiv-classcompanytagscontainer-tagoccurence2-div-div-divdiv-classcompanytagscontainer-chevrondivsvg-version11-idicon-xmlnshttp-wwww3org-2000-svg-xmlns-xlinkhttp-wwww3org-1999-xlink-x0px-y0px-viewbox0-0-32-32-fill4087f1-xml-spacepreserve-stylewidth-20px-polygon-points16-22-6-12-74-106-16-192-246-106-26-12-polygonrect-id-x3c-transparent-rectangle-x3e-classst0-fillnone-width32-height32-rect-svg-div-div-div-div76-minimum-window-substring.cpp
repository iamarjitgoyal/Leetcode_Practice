class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }

        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        int left = 0, right = 0, requiredChars = targetFreq.size();
        int formedChars = 0;
        unordered_map<char, int> windowFreq;

        int minLen = INT_MAX, minLeft = 0, minRight = 0;

        while (right < s.length()) {
            char currentChar = s[right];
            windowFreq[currentChar]++;

            if (targetFreq.find(currentChar) != targetFreq.end() && windowFreq[currentChar] == targetFreq[currentChar]) {
                formedChars++;
            }

            while (formedChars == requiredChars) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                    minRight = right + 1;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;

                if (targetFreq.find(leftChar) != targetFreq.end() && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formedChars--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
