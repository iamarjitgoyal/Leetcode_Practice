/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* node1 = nullptr;
        ListNode* node2 = nullptr;
        
        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }
        
        node1 = fast;
        
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        node2 = slow;
        
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
        
        return head;
    }
};
