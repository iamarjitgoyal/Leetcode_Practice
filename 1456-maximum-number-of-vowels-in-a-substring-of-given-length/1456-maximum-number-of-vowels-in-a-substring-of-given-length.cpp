class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelCount = 0;
        int vowelCount = 0;
        
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
        }
        
        maxVowelCount = vowelCount;
        
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i-k])) {
                vowelCount--;
            }
            
            if (isVowel(s[i])) {
                vowelCount++;
            }
            
            maxVowelCount = max(maxVowelCount, vowelCount);
        }
        
        return maxVowelCount;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
