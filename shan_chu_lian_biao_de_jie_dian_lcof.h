#include "common.h"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dumb = new ListNode;
        dumb->next = head;
        ListNode* cur = head;
        ListNode* prev = dumb;
        while (cur != NULL && cur->val != val)
        {
            prev = cur;
            cur = prev->next;
        }

        //删除节点
        prev->next = cur->next;

        return dumb->next;
    }
};