class Solution {
public:
    int dp[(int)5e4 + 1];
    
    int calculateTime(int node, vector<int> &time, vector<int> adj[]) {
        if (dp[node] != -1)
            return dp[node];

        int maxTime = 0;
        for (auto prerequisite : adj[node])
            maxTime = max(maxTime, calculateTime(prerequisite, time, adj));

        return dp[node] = time[node - 1] + maxTime;
    }

    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        memset(dp, -1, sizeof(dp));

        vector<int> prerequisites[n + 1], outDegree(n + 1);
        for (auto relation : relations) {
            prerequisites[relation[1]].push_back(relation[0]);
            outDegree[relation[0]]++;
        }

        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (outDegree[i] == 0) {
                minTime = max(minTime, calculateTime(i, time, prerequisites));
            }
        }

        return minTime;
    }
};
