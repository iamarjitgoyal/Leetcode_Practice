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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* next = second->next;
        head = second;
        
        while (first && second) {
            // swapping adjacent nodes
            second->next = first;
            first->next = next;
            if (prev) {
                prev->next = second;
            }
            prev = first;
            // updating the pointers
            first = next;
            if (first) {
                second = first->next;
                if (second) {
                    next = second->next;
                }
            }
        }
        return head;
    }
};
