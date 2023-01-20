class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(nums, 0, seq, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& seq, vector<vector<int>>& res) {
        if (seq.size() > 1) res.push_back(seq);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (seq.empty() || nums[i] >= seq.back()) {
                used.insert(nums[i]);
                seq.push_back(nums[i]);
                dfs(nums, i + 1, seq, res);
                seq.pop_back();
            }
        }
    }
};



// res : a set of vectors that will store all the possible non-decreasing subsequences of the given array with at least two elements.

// temp : a vector that will temporarily store the current subsequence.

// nums : the input array

// start : the starting index of the array to explore.

// First, the function checks if the current temp vector has more than one element, if yes then it is inserted into the set.

// Then the function enters a loop that starts from the start index and goes till the end of the array.

// In the loop, if the temp vector is empty or the current element of the array is greater than or equal to the last element of the temp vector, the current element is added to the temp vector and the helper function is called recursively with the updated temp vector, the same array and the next index i+1.

// After the recursive call, the last element of the temp vector is removed so that the temp vector is ready for the next exploration.

// Finally, the set is converted to a vector and returned.