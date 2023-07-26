class Solution {
public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
        int n = dist.size();
        int left = 1;
        int right = 10000000;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double total_time = 0;
            
            for (int i = 0; i < n - 1; i++) {
                total_time += std::ceil(static_cast<double>(dist[i]) / mid); 
            }
            
            total_time += static_cast<double>(dist[n - 1]) / mid; 
            
            if (total_time <= hour) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if (left > 10000000) {
            return -1;
        }
        return left;
    }
};
