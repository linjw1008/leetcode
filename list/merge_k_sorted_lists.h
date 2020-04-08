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
        ListNode* p = new ListNode(-1);
        ListNode* prev = p;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == NULL ? l2 : l1;
        
        return p->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        int pos = lists.size() - 1;
        while (--pos >= 0)
            lists[pos] = mergeList(lists[pos], lists[pos + 1]);
        
        return lists[0];
    }
};