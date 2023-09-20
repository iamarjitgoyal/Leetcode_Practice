class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size(); 
        
        int n = nums.size();
        int maxLength = -1;
        int currentSum = 0;
        unordered_map<int, int> prefixSum; 
        
        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            
            if (currentSum == target) {
                maxLength = max(maxLength, i + 1);
            }
            
            int requiredPrefixSum = currentSum - target;
            if (prefixSum.count(requiredPrefixSum)) {
                maxLength = max(maxLength, i - prefixSum[requiredPrefixSum]);
            }
            
            prefixSum[currentSum] = i;
        }
        
        return maxLength == -1 ? -1 : n - maxLength;
    }
};
