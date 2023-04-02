class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1, count = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long) spells[i] * potions[mid] >= success) {
                    count = m - mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            pairs[i] = count;
        }
        return pairs;
    }
};
