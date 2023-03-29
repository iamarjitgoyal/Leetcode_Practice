class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0, ans = 0;
        for (int i = n - 1; i >= 0 && satisfaction[i] > -sum; i--) {
            sum += satisfaction[i];
            ans += sum;
        }
        return ans;
    }
};
