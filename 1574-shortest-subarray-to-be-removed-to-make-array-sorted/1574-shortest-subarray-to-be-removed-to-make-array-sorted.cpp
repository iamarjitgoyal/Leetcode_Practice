class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < n - 1 && arr[l] <= arr[l + 1]) l++;
        if (l == n - 1) return 0;
        while (r > 0 && arr[r - 1] <= arr[r]) r--;
        int res = min(n - l - 1, r);
        int i = 0, j = r;
        while (i <= l && j <= n - 1) {
            if (arr[i] <= arr[j]) {
                res = min(res, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
