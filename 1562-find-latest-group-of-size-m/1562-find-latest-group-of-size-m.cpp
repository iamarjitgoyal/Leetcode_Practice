class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        vector<int> cnt(n + 2, 0);
        int res = -1;
        for (int i = 0; i < n; i++) {
            int pos = arr[i];
            int left = cnt[pos - 1];
            int right = cnt[pos + 1];
            if (left == m || right == m || (left + right + 1) == m) res = i;
            cnt[pos] = cnt[pos - left] = cnt[pos + right] = left + right + 1;
        }
        return res;
    }
};
