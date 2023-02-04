class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1_count(26), s2_count(26);
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (s1_count == s2_count) return true;
            s2_count[s2[i + s1.length()] - 'a']++;
            s2_count[s2[i] - 'a']--;
        }
        return s1_count == s2_count;
    }
};
