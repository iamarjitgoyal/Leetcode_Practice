class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto& edge : edges) {
            int x = find(edge[0], parent);
            int y = find(edge[1], parent);
            if (x != y) parent[x] = y;
        }
        vector<int> size(n);
        for (int i = 0; i < n; ++i) size[find(i, parent)]++;
        long long ans = (long long)n * (n - 1) / 2;
        for (int i = 0; i < n; ++i) {
            if (size[i] > 1) ans -= (long long)size[i] * (size[i] - 1) / 2;
        }
        return ans;
    }
};
