#include <vector>
#include <unordered_map>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        
        for (auto num : nums) {
            frequencyMap[num]++;
        }

        int operations = 0;

        for (auto entry : frequencyMap) {
            int frequency = entry.second;

            if (frequency == 1) {
                return -1;
            }

            operations += frequency / 3;
            if (frequency % 3) {
                operations++;
            }
        }

        return operations;
    }
};
