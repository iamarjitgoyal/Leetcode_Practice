class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxScore = 0, minScore = 0;
        k--;
        int n = weights.size();
        vector<long long> diffScores;

        for (int i = 1; i < n; i++) {
            diffScores.push_back(weights[i] + weights[i - 1]);
        }

        sort(diffScores.begin(), diffScores.end(), greater<long long>());

        int sizeDiffScores = diffScores.size();

        for (int i = 0; i < k; i++) {
            maxScore += diffScores[i];
            minScore += diffScores[sizeDiffScores - 1 - i];
        }

        return (maxScore - minScore);
    }
};
