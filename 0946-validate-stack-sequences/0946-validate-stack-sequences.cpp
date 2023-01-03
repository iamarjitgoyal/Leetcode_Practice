class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
        int p1 = 0, p2 = 0;
        while (p2 < popped.size()) {
            while (st.empty() || st.top() != popped[p2]) {
                if (p1 == pushed.size()) {
                    return false;
                }
                st.push(pushed[p1++]);
            }
            st.pop();
            p2++;
        }
        return true;
    }
};