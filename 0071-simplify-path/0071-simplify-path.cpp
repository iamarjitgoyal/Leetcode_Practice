class Solution {
public:
    string simplifyPath(string path) {
        string res, dir;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue;
            if (dir == ".." && !stk.empty()) stk.pop_back();
            else if (dir != "..") stk.push_back(dir);
        }
        for (string s : stk) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
