/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* l3 = ret;
        short tmp = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = (l1->val + l2->val + tmp) > 9 ? (l1->val + l2->val + tmp - 10) : (l1->val + l2->val + tmp);
            tmp = (l1->val + l2->val + tmp) > 9 ? 1:0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = (l1->val + tmp) > 9 ? (l1->val + tmp - 10) : (l1->val + tmp);
            tmp = (l1->val + tmp) > 9 ? 1:0;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = (l2->val + tmp) > 9 ? (l2->val + tmp - 10) : (l2->val + tmp);
            tmp = (l2->val + tmp) > 9 ? 1:0;
            l2 = l2->next;
        }
        if(tmp != 0)
        {
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = tmp;
        }
        return ret->next;
    }
};