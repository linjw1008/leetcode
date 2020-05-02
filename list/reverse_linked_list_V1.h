#include "common.h"

//非递归法

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode* prev = head;
        ListNode* next = prev->next;
        ListNode* sentinel = new ListNode;
        sentinel->next = head;
        
        while (prev->next != NULL)
        {
            prev->next = next->next;
            next->next = sentinel->next;
            sentinel->next = next;
            next = prev->next;
        }
        
        
        return sentinel->next;
    };    
};