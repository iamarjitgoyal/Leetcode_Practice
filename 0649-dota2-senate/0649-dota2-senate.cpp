class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front(); radiant.pop();
            int d_idx = dire.front(); dire.pop();
            if (r_idx < d_idx) {
                radiant.push(r_idx + n);
            } else {
                dire.push(d_idx + n);
            }
        }
        return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
    }
};
