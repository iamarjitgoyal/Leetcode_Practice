class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> lake;
        set<int> dry;
        vector<int> ans(rains.size(), -1);
        for (int i = 0; i < rains.size(); i++) {
            int r = rains[i];
            if (r == 0) {
                dry.insert(i);
                ans[i] = 1;
                continue;
            }
            if (lake.count(r)) {
                auto it = dry.upper_bound(lake[r]);
                if (it == dry.end()) return {};
                int d = *it;
                dry.erase(it);
                lake.erase(r);
                ans[d] = r;
            }
            lake[r] = i;
        }
        return ans;
    }
};
