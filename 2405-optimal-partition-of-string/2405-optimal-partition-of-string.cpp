class Solution {
public:
    int partitionString(string s) {
        int curSubstr = 0;
        int i = 0, ans = 0;
        while(i < s.size()){
            int idx = s[i] - 'a';
            if(curSubstr & (1 << idx)) {
                curSubstr = 0;
                ans++;
            }
            curSubstr |= (1 << idx);
            i++;
        }
        return ans + 1;
    }
};
