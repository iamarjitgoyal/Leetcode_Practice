class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adjList(n);
        
        for (const auto& road : roads) {
            adjList[road[0]].insert(road[1]);
            adjList[road[1]].insert(road[0]);
        }
        
        int maxRank = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = adjList[i].size() + adjList[j].size();
                if (adjList[i].count(j)) {
                    rank -= 1;
                }
                maxRank = std::max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};
