class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp(dist);
            for (auto e : flights) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] == INT_MAX) continue;
                temp[v] = min(temp[v], dist[u] + w);
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
