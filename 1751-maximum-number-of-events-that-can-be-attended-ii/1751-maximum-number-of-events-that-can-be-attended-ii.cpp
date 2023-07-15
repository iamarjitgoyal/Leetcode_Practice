class Solution {
public:
    int binarySearch(int index, vector<vector<int>>& events, int value) {
        int lo = index;
        int hi = events.size() - 1;
        int req = -1;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (events[mid][0] > value) {
                req = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return req;
    }

    int helper(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if (i >= events.size() || k == 0 || i == -1) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int index = binarySearch(i + 1, events, events[i][1]);

        int choice1 = events[i][2] + helper(index, events, k - 1, dp);
        int choice2 = helper(i + 1, events, k, dp);

        return dp[i][k] = max(choice1, choice2);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 5, vector<int>(k + 1, -1));
        return helper(0, events, k, dp);
    }
};
