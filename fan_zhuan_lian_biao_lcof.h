#include "common.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* dumb = new ListNode;
        dumb->next = head;
        ListNode* cur = head, *next = cur->next;

        while (cur->next != NULL)
        {
            cur->next = next->next;
            next->next = dumb->next;
            dumb->next = next;
            next = cur->next;
        }

        return dumb->next;
    }
};