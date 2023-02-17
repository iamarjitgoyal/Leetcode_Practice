class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_local = INT_MIN;
        for (int i = 0; i < n-2; i++) {
            max_local = max(max_local, nums[i]);
            if (max_local > nums[i+2]) {
                return false;
            }
        }
        return true;
    }
};
