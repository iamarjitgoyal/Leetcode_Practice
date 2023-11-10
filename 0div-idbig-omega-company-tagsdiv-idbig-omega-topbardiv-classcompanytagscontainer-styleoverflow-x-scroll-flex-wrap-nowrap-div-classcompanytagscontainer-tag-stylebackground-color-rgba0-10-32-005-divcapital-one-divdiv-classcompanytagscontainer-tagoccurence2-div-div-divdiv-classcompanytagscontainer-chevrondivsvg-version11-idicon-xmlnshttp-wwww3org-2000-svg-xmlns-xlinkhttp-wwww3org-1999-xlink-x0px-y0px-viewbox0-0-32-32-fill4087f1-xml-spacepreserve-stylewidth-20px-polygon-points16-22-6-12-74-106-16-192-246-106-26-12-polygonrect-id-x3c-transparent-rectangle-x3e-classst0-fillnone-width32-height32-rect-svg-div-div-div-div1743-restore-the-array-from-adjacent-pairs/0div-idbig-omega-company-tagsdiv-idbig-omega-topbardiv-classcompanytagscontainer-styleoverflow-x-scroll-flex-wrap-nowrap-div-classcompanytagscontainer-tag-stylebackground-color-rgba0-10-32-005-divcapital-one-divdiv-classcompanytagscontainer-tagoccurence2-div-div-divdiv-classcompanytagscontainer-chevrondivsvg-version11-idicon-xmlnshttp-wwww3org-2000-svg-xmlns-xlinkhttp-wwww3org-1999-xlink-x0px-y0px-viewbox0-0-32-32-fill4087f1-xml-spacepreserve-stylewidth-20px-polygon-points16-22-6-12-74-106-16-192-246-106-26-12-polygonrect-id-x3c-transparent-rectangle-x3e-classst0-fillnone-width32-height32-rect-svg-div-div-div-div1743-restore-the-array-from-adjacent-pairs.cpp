class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        unordered_map<int, vector<int>> adjMap;
        for (const auto& pair : adjacentPairs) {
            adjMap[pair[0]].push_back(pair[1]);
            adjMap[pair[1]].push_back(pair[0]);
        }


        int startNode;
        for (const auto& entry : adjMap) {
            if (entry.second.size() == 1) {
                startNode = entry.first;
                break;
            }
        }


        vector<int> result;
        unordered_set<int> visited;
        dfs(startNode, adjMap, visited, result);

        return result;
    }

private:
    void dfs(int currentNode, unordered_map<int, vector<int>>& adjMap, unordered_set<int>& visited, vector<int>& result) {
        visited.insert(currentNode);
        result.push_back(currentNode);

        for (int neighbor : adjMap[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adjMap, visited, result);
            }
        }
    }
};
