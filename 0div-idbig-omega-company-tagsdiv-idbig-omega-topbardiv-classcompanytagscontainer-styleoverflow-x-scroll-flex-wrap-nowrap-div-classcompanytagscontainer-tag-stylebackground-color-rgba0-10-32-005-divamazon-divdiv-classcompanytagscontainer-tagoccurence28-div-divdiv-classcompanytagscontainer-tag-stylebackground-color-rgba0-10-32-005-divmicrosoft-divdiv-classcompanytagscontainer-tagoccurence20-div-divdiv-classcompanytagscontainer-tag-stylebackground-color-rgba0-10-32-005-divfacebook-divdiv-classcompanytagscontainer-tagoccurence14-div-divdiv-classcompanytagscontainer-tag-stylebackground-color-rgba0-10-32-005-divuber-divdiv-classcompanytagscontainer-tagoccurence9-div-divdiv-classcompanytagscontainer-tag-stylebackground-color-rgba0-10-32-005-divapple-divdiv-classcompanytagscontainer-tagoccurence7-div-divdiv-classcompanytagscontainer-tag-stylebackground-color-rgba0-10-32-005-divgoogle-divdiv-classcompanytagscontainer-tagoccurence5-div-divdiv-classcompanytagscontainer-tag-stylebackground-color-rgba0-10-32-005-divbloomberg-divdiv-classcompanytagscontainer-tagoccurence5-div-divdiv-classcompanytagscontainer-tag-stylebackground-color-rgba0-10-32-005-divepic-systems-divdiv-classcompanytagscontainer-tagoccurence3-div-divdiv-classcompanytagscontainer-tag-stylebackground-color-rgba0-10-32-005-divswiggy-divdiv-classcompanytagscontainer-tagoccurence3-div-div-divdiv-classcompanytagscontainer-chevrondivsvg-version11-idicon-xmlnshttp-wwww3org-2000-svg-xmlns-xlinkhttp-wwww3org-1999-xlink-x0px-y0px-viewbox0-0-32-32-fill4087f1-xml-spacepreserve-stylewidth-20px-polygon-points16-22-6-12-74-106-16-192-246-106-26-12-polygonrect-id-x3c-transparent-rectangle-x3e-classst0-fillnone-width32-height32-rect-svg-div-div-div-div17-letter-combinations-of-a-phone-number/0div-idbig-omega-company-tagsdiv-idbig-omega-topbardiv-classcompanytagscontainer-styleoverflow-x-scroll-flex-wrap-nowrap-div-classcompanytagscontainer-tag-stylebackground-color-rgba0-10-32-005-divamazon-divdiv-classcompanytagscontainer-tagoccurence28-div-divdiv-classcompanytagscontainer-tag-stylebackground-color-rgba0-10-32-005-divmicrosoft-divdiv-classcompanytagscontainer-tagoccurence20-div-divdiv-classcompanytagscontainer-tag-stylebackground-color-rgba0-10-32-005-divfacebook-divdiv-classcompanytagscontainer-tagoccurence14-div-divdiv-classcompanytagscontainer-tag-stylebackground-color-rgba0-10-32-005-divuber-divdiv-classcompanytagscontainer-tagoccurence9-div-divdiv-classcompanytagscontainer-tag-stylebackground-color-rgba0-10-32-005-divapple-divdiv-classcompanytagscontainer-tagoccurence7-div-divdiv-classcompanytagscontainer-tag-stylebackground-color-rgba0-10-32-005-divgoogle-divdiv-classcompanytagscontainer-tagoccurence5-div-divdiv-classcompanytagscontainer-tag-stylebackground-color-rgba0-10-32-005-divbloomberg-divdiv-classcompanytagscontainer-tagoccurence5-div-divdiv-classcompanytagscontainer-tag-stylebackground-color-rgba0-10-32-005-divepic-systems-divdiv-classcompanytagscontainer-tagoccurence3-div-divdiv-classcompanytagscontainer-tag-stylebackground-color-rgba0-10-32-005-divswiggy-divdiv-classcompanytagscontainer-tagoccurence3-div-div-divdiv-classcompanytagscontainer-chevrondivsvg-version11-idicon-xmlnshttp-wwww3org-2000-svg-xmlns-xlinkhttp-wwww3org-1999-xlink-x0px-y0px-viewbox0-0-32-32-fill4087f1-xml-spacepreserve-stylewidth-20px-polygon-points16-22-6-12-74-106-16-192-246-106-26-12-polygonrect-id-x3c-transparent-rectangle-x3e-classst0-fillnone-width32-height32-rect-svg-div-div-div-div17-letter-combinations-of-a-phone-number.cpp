class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        vector<string> digitLetters = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current;
        generateCombinations(digits, 0, digitLetters, current, result);
        
        return result;
    }
    
    void generateCombinations(const string& digits, int index, const vector<string>& digitLetters, string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '2';
        for (char letter : digitLetters[digit]) {
            current.push_back(letter);
            generateCombinations(digits, index + 1, digitLetters, current, result);
            current.pop_back();
        }
    }
};
