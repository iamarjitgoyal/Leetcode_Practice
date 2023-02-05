class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.empty() || p.empty() || s.size() < p.size()) return res;

        unordered_map<char, int> p_map, window_map;
        for (char c : p) p_map[c]++;

        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right];
            window_map[c]++;
            right++;

            if (right - left == p.size()) {
                if (p_map == window_map) res.push_back(left);
                window_map[s[left]]--;
                if (window_map[s[left]] == 0) window_map.erase(s[left]);
                left++;
            }
        }

        return res;
    }
};