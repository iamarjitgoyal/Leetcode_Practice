class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int left = 0, right = arr[n - 1];
        int res = 0, diff = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] > mid) sum += mid;
                else sum += arr[i];
            }
            if (abs(target - sum) < diff || (abs(target - sum) == diff && mid < res)) {
                diff = abs(target - sum);
                res = mid;
            }
            if (sum < target) left = mid + 1;
            else right = mid - 1;
        }
        return res;
    }
};
