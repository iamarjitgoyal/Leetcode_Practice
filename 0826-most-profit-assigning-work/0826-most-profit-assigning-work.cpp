class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        // create a vector of pairs to store the difficulty and profit of each job
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        // sort the jobs by difficulty in ascending order
        sort(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });

        // sort the workers by ability in ascending order
        sort(worker.begin(), worker.end());

        int res = 0;
        int maxProfit = 0;
        int i = 0;
        int j = 0;

        // loop through the workers and jobs and calculate the maximum profit
        while (i < m && j < n) {
            if (worker[i] >= jobs[j].first) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            } else {
                res += maxProfit;
                i++;
            }
        }

        // add the maximum profit for remaining workers
        while (i < m) {
            res += maxProfit;
            i++;
        }

        return res;
    }
};
