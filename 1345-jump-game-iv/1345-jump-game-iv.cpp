class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == n - 1) {
                return dist[curr];
            }
            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }
            for (int next : indices[arr[curr]]) {
                if (next != curr && dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
            indices[arr[curr]].clear();
        }
        return -1;
    }
};