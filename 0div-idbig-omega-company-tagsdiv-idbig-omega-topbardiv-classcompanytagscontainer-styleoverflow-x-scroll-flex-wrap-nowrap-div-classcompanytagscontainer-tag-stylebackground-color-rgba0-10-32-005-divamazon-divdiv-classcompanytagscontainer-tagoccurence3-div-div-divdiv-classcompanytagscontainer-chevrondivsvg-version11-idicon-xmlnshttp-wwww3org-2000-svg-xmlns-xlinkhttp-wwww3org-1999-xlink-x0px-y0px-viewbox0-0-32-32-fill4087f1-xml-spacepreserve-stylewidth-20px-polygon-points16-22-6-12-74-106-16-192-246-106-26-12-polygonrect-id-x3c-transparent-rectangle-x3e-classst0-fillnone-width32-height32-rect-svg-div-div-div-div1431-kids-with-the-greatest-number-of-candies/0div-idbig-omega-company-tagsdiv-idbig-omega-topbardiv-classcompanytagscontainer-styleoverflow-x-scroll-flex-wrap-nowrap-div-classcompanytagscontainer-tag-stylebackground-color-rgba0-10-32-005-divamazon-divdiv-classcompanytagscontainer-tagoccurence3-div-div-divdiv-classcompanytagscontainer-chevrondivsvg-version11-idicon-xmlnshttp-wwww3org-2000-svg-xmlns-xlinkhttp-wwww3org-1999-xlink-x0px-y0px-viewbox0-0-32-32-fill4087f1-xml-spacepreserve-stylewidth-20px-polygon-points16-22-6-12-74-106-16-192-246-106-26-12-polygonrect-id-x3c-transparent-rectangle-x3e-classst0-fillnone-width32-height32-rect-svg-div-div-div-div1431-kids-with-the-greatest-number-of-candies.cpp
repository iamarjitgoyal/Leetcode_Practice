class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = candies[0];
        for(int i = 1; i < n; i++) {
            if(candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        vector<bool> result(n, false);
        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxCandies) {
                result[i] = true;
            }
        }
        return result;
    }
};
