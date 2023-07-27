class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long left = 1, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        while (left < right) {
            long long target = right - (right - left) / 2;
            long long total = accumulate(batteries.begin(), batteries.end(), 0LL, [&target](long long a, int b) { return a + min(static_cast<long long>(b), target); });
            if (total >= target * n) {
                left = target;
            } else {
                right = target - 1;
            }
        }
        return left;
    }
};