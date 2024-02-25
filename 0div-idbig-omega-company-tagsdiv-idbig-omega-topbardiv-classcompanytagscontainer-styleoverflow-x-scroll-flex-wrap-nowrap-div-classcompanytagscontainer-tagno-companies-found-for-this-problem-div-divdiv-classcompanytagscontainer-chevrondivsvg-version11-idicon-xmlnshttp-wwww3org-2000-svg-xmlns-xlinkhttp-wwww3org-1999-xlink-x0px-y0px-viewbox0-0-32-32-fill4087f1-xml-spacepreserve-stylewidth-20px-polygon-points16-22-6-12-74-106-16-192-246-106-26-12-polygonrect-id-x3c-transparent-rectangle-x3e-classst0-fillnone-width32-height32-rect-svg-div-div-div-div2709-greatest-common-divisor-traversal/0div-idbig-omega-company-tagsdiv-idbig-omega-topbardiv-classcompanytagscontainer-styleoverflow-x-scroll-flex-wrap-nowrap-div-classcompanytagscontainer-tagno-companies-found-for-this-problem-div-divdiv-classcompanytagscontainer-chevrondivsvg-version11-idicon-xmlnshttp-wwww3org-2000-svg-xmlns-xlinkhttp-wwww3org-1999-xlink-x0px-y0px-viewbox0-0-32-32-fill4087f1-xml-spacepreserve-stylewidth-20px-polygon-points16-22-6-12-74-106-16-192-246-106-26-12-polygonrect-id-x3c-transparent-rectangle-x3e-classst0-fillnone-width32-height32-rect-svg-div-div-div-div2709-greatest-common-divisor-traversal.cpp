class Solution {
public:
    unordered_map<int, vector<int>> primeToIndexMap;
    unordered_map<int, vector<int>> indexToPrimeMap;

    void depthFirstSearch(int currentIndex, vector<int>& visitedIndices, unordered_map<int,bool>& visitedPrimes) {
        if (visitedIndices[currentIndex]) return;
        visitedIndices[currentIndex] = true;

        for (auto &currentPrime : indexToPrimeMap[currentIndex]) {
            if (visitedPrimes[currentPrime]) 
                continue;

            visitedPrimes[currentPrime] = true;

            for (auto &nextIndex : primeToIndexMap[currentPrime]) {
                if (visitedIndices[nextIndex]) 
                    continue;
                
                depthFirstSearch(nextIndex, visitedIndices, visitedPrimes);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            for (int factor = 2; factor * factor <= currentNum; factor++) {
                if (currentNum % factor == 0) {
                    primeToIndexMap[factor].push_back(i);
                    indexToPrimeMap[i].push_back(factor);

                    while (currentNum % factor == 0)
                        currentNum /= factor;
                }
            }

            if (currentNum > 1) {
                primeToIndexMap[currentNum].push_back(i);
                indexToPrimeMap[i].push_back(currentNum);
            }
        }

        vector<int> visitedIndices(nums.size(), 0);
        unordered_map<int, bool> visitedPrimes;
        depthFirstSearch(0, visitedIndices, visitedPrimes);

        for (int i = 0; i < visitedIndices.size(); i++) {
            if (!visitedIndices[i]) 
                return false;
        }

        return true;
    }
};