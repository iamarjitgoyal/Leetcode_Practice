class Solution {
public:
    bool isCharSet(int& charSet, int& idx) {
        return charSet & (1 << idx);
    }

    void setChar(int& charSet, int& idx) {
        charSet |= (1 << idx);
    }

    int partitionString(string s) {
        int charSet = 0;
        int i = 0, ans = 1;
        while(i < s.size()){
            int idx = s[i] - 'a';
            if(isCharSet(charSet, idx)) {
                charSet = 0;
                ans++;
            }
            setChar(charSet, idx);
            i++;
        }
        return ans;
    }
};
