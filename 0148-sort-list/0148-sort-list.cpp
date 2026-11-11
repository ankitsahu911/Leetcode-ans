class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int step = 1; step < n; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);

                auto [mergedHead, mergedTail] = merge(left, right);
                prev->next = mergedHead;
                prev = mergedTail;
            }
        }

        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < step; ++i) {
            head = head->next;
        }
        ListNode* nextPart = head->next;
        head->next = nullptr;
        return nextPart;
    }

    std::pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        while (tail->next) {
            tail = tail->next;
        }

        return {dummy.next, tail};
    }
};