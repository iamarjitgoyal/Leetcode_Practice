class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Convert the vector to an unordered_set for O(1) lookup times
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* current = dummy;

        // Traverse the list
        while (current->next != nullptr) {
            if (numSet.count(current->next->val)) {
                // Remove the node if its value exists in numSet
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        // Return the modified list
        ListNode* modifiedHead = dummy->next;
        delete dummy; // Free the dummy node
        return modifiedHead;
    }
};