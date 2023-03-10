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
private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
    }

    int getRandom() {
        ListNode* current = head;
        int count = 1;
        int result = 0;
        
        while (current) {
            int r = rand() % count + 1;
            if (r == count) {
                result = current->val;
            }
            current = current->next;
            count++;
        }        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */