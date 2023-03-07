class Solution {
public:
    long long minimumTime(std::vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long left = 0, right = (long long)time[0] * totalTrips;
        while (left < right) {
            long long mid = (left + right) / 2;
            long long trips = 0;
            for (int t : time) {
                trips += mid / t;
                if (trips >= totalTrips) break;
            }
            if (trips >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
