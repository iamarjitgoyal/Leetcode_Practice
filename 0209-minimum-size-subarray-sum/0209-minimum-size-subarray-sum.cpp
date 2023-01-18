class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, sum = 0, minLen = INT_MAX;
        // Two pointers approach to find the minimal length subarray
        while (right < n) {
            sum += nums[right];
            right++;
            while (sum >= target) {
                minLen = min(minLen, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
