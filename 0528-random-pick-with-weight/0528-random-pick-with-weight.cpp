class Solution {
public:
    vector<int> prefix_sum;
    int total_sum;

    Solution(vector<int>& w) {
        total_sum = 0;
        for (int weight : w) {
            total_sum += weight;
            prefix_sum.push_back(total_sum);
        }
    }
    
    int pickIndex() {
        int random_num = rand() % total_sum; // generate a random number between 0 and total_sum-1
        int left = 0, right = prefix_sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (random_num >= prefix_sum[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
