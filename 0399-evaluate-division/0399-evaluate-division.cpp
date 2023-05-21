class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            const double value = values[i];
            
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }
        
        // Perform DFS for each query
        vector<double> results;
        for (const auto& query : queries) {
            const string& src = query[0];
            const string& dest = query[1];
            
            if (!graph.count(src) || !graph.count(dest)) {
                results.push_back(-1.0);
            } else {
                unordered_map<string, bool> visited;
                double result = dfs(src, dest, graph, visited);
                results.push_back(result);
            }
        }
        
        return results;
    }
    
private:
    double dfs(const string& src, const string& dest, const unordered_map<string, unordered_map<string, double>>& graph, unordered_map<string, bool>& visited) {
        if (src == dest) {
            return 1.0;
        }
        
        visited[src] = true;
        
        for (const auto& neighbor : graph.at(src)) {
            const string& next = neighbor.first;
            const double weight = neighbor.second;
            
            if (!visited[next]) {
                double result = dfs(next, dest, graph, visited);
                if (result != -1.0) {
                    return result * weight;
                }
            }
        }
        
        return -1.0;
    }
};
