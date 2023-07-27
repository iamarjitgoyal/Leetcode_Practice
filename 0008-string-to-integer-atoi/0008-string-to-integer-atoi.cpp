class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;
        
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (result > (std::numeric_limits<int>::max() - digit) / 10) {
                return (sign == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};