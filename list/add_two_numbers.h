#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode* dumb = new ListNode();
        ListNode* prev = dumb;
        
        while (l1 != NULL && l2 != NULL)
        {
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            //要先算carry!!!!!
            carry = sum / 10;
            //然后再取余数
            sum = sum % 10;
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
        
        while (l1 != NULL)
        {
            sum = l1->val + carry;
            l1 = l1->next;
            carry = sum / 10;
            sum = sum % 10;
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
        
        while (l2 != NULL)
        {
            sum = l2->val + carry;
            l2 = l2->next;
            carry = sum / 10;
            sum = sum % 10;
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
        
        if (carry != 0)
            prev->next = new ListNode(carry);
        
        return dumb->next;
    }
};