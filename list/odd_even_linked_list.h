#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dumb = new ListNode();
        dumb->next = head;
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* tmp = even;
        
        while (even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = tmp;

        return dumb->next;
    }
};