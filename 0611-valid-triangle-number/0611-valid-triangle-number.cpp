class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0; // if array is empty or has only one element return 0
        int count = 0;
        sort(nums.begin(), nums.end()); // sort the array in ascending order
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end()); // remove all zeroes
        n = nums.size();
        // iterate over all possible values of the first side
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2; // initialize k as i+2
            // iterate over all possible values of the second side
            for (int j = i + 1; j < n - 1; j++) {
                // move k to the right until the condition is met
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                // update the count
                count += k - j - 1; 
            }
        }
        return count;
    }
};
