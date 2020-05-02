
#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumb = new ListNode();
        dumb->next = head;
        ListNode* prev = dumb, *cur = head;
        
        while (cur != NULL)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = prev->next;        
            }
        }
        
        return dumb->next;
    }
};