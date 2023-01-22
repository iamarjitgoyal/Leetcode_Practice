class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int target=0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};