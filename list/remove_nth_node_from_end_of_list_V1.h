//删除链表的倒数第N个节点
//遍历两次法

#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel = new ListNode;
        sentinel->next = head;
        ListNode* prev = sentinel, *next = sentinel->next;
        int len = 0;
        
        //统计节点
        while (next != NULL)
        {
            len++;
            next = next->next;
        }
        
        next = prev->next;
        //删除倒数第n个节点
        for (int i = 0; i < len - n; ++i)
        {
            prev = prev->next;
            next = prev->next;
        }
        
        //删除
        prev->next = next->next;
        
        return sentinel->next;
    }
};