class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (similar(strs[i], strs[j])) {
                    int parent_i = find(parent, i);
                    int parent_j = find(parent, j);
                    if (parent_i != parent_j) {
                        parent[parent_i] = parent_j;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
    
private:
    bool similar(const string& s1, const string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
            if (diff > 2) {
                return false;
            }
        }
        return true;
    }
    
    int find(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
};
