class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if ((long long) spells[i] * potions[mid] >= success) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
};