#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* spreadList(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //若是奇数个数的节点，返回中间节点的下一个
        //若是偶数，直接返回
        if (fast == NULL)
            return slow;
        else
            return slow->next;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return p;
    }
    
    bool cmpTwoList(ListNode* l1, ListNode* l2)
    {
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        
        bool ans = false;
        
        ListNode* mid = spreadList(head);
        mid = reverseList(mid);
        
        if (cmpTwoList(head, mid))
            ans = true;
        
        //恢复链表
        mid = reverseList(mid);
        
        return ans;
    }
    
    
};