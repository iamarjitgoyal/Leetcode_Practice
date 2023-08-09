class Solution {
public:
    bool canFormPairsWithMaxDifference(vector<int>& nums, int maxDiff, int p) {
        int n = nums.size();
        int pairs = 0;
        int i = 0;
        
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                pairs++;
                i++;
            }
            if (pairs >= p)
                return true;
            i++;
        }
        
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minMaxDiff = 0, maxMaxDiff = nums[n - 1] - nums[0];
        
        while (minMaxDiff < maxMaxDiff) {
            int midMaxDiff = minMaxDiff + (maxMaxDiff - minMaxDiff) / 2;
            
            if (canFormPairsWithMaxDifference(nums, midMaxDiff, p))
                maxMaxDiff = midMaxDiff;
            else
                minMaxDiff = midMaxDiff + 1;
        }
        
        return minMaxDiff;
    }
};