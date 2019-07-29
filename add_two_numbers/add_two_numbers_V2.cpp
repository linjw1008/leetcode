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
        ListNode ret(0);
        ListNode* l3 = &ret;
        short carry = 0;
        int sum = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 == nullptr)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }else if(l2 == nullptr)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }else
            {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            carry = sum > 9 ? 1 : 0;
        } 
        if(carry) l3->next = new ListNode(carry);

        return (&ret)->next;
    }
};