class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = 1;
        while(n<nums.size()){
            nums[n]+=nums[n-1];
            n++;
        }
        return nums;
    }
};