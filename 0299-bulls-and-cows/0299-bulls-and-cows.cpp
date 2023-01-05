class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> secretCounts, guessCounts;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secretCounts[secret[i]]++;
                guessCounts[guess[i]]++;
            }
        }
        for (const auto& [digit, count] : guessCounts) {
            if (secretCounts.count(digit)) {
                cows += min(secretCounts[digit], count);
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
