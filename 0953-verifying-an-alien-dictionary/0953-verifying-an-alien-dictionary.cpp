class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            for (int j = 0; j < len; j++) {
                if (map[word1[j]] < map[word2[j]]) {
                    break;
                }
                else if (map[word1[j]] > map[word2[j]]) {
                    return false;
                }
                else {
                    if (j == len - 1 && word1.size() > word2.size()) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
