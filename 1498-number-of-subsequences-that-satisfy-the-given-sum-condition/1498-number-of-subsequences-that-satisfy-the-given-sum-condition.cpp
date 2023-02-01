class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = (pw[i - 1] * 2) % 1000000007;
        }
        int res = 0, l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pw[r - l++]) % 1000000007;
            }
        }
        return res;
    }
};
