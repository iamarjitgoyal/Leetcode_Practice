class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
        int maxSum = 0;
        int n = values.size();
        for (int i = 0; i < n / 2; i++) {
            int twinIndex = n - 1 - i;
            int sum = values[i] + values[twinIndex];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
