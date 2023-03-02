class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 0;
        int count = 0;
        char prev = '\0';
        
        while (i < n) {
            if (chars[i] == prev) {
                count++;
            } else {
                if (count > 0) {
                    chars[j++] = prev;
                    if (count > 1) {
                        string num = to_string(count);
                        for (char c : num) {
                            chars[j++] = c;
                        }
                    }
                }
                prev = chars[i];
                count = 1;
            }
            i++;
        }
        
        if (count > 0) {
            chars[j++] = prev;
            if (count > 1) {
                string num = to_string(count);
                for (char c : num) {
                    chars[j++] = c;
                }
            }
        }
        
        return j;
    }
};
