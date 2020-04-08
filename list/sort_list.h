#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeList(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeList(l2->next, l1);
            return l2;
        }
    }
    
    ListNode* mergeSort(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        //利用快慢指针找到中点
        ListNode* fast = head;
        ListNode* mid = head;
        ListNode* preMid = head;
        while (fast != NULL && fast->next != NULL)
        {
            preMid = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        
        preMid->next = NULL;
        head = mergeSort(head);
        mid = mergeSort(mid);
        
        //合并
        return mergeList(head, mid);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};