class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int leftBound = k, rightBound = k;
        int minElement = nums[k];
        int maxScore = minElement;

        while (leftBound > 0 || rightBound < nums.size() - 1) {
            if (leftBound == 0 || (rightBound < nums.size() - 1 && nums[rightBound + 1] > nums[leftBound - 1])) {
                rightBound++;
            } else {
                leftBound--;
            }
            minElement = min(minElement, min(nums[leftBound], nums[rightBound]));
            maxScore = max(maxScore, minElement * (rightBound - leftBound + 1));
        }
        
        return maxScore;
    }
};
