class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val <= curr->next->val) {
                curr = curr->next;
            } else {
                ListNode* target = curr->next;
                curr->next = target->next;

                ListNode* prev = &dummy;
                while (prev->next->val < target->val) {
                    prev = prev->next;
                }

                target->next = prev->next;
                prev->next = target;
            }
        }

        return dummy.next;
    }
};