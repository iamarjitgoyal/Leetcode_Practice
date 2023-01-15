class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; // To store the final result
        vector<string> curr; // To store the current partition
        dfs(s, 0, curr, res); 
        return res;
    }

private:
    // DFS function to find all possible partitions
    void dfs(string s, int start, vector<string>& curr, vector<vector<string>>& res) {
        if (start == s.size()) {
            // If we have reached the end of the string, add the current partition to the result
            res.push_back(curr);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                // if the substring is a palindrome, add it to the current partition
                curr.push_back(s.substr(start, i - start + 1));
                // Recursively call the function for the next substring
                dfs(s, i + 1, curr, res);
                // Backtrack by removing the last added substring
                curr.pop_back();
            }
        }
    }
    
    // Function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};
