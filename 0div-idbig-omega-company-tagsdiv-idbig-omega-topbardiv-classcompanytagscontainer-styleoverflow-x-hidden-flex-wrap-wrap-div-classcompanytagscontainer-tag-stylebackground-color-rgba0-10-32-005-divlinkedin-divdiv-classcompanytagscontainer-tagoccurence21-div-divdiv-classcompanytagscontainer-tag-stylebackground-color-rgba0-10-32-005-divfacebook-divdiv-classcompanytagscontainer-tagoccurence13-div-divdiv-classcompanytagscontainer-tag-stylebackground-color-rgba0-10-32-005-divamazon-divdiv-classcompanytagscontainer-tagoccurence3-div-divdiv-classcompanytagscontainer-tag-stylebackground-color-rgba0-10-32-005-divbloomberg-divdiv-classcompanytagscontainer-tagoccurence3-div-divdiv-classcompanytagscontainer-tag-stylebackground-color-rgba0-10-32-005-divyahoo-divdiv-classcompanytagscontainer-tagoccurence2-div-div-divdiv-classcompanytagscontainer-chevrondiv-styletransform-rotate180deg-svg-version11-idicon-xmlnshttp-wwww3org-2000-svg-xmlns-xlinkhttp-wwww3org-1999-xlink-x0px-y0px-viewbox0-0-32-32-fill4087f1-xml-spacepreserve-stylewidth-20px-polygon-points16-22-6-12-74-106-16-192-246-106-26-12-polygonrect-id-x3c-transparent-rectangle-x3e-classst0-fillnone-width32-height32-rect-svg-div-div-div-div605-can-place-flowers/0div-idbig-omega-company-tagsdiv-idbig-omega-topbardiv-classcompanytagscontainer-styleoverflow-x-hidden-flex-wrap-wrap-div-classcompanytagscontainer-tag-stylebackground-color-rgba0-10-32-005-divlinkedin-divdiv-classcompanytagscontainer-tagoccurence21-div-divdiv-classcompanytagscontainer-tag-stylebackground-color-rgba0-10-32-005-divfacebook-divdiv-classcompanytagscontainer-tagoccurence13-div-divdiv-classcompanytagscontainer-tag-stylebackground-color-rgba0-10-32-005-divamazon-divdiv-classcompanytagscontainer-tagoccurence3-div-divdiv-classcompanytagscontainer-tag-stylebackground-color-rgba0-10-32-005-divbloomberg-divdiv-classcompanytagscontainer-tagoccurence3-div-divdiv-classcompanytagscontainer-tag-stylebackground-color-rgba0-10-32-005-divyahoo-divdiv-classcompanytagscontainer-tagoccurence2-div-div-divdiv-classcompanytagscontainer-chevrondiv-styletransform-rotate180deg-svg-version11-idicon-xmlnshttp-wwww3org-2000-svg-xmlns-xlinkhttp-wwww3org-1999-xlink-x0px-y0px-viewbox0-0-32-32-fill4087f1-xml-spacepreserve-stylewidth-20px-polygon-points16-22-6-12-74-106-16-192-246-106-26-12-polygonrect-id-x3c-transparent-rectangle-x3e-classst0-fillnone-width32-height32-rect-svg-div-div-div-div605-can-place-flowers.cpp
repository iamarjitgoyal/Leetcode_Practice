class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int i = 0;
        while (i < flowerbed.size()) {
            if (flowerbed[i] == 0) {
                bool prevEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool nextEmpty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                if (prevEmpty && nextEmpty) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            i++;
        }
        return count >= n;
    }
};
