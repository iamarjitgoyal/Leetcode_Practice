#include <vector>

class Solution {
public:
    bool validPartition(std::vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return false;
        bool prev2Consecutive = true;
        bool prev3Equal = false;
        bool prev3Consecutive = n > 1 && nums[0] == nums[1];

        for (int i = 2; i < n; i++) {
            bool currentValid = false;

            if (nums[i] == nums[i - 1] && prev3Equal) {
                currentValid = true;
            } else if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && prev2Consecutive) {
                currentValid = true;
            } else if (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && prev2Consecutive) {
                currentValid = true;
            }

            prev2Consecutive = prev3Equal;
            prev3Equal = prev3Consecutive;
            prev3Consecutive = currentValid;
        }

        return prev3Consecutive;
    }
};
