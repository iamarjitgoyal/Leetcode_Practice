class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int curr_weight = 0, num_days = 1;
            for (int w : weights) {
                if (curr_weight + w > mid) {
                    num_days++;
                    curr_weight = 0;
                }
                curr_weight += w;
            }
            if (num_days > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
