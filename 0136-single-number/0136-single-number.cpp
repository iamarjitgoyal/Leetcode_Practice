class Solution {
public:
    int singleNumber(vector<int>& A) {
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            result ^= A[i];
        }
        return result;
    }
};