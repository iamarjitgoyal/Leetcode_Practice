class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0, max_count = 0;
        unordered_map<int, int> basket;
        while (end < fruits.size()) {
            basket[fruits[end]]++;
            while (basket.size() > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0) {
                    basket.erase(fruits[start]);
                }
                start++;
            }
            max_count = max(max_count, end - start + 1);
            end++;
        }
        return max_count;
    }
};
