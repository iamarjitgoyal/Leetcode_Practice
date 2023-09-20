class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prevValue = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentVal = romanValues[s[i]];
            
            if (currentVal < prevValue) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
            
            prevValue = currentVal;
        }
        
        return result;
    }
};
