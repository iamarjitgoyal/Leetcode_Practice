class Solution {
public:
    static int countBits(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = countBits(a);
            int countB = countBits(b);
            if (countA == countB) {
                return a < b;
            }
            
            return countA < countB;
        });

        return arr;
    }
};
