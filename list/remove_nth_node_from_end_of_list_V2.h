//删除链表的倒数第N个节点
//双指针法

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
        
        ListNode* p1 = sentinel;
        ListNode* p2 = sentinel;
        
        //把p2向前移动n个位置
        for (int i = 0; i < n; ++i)
            p2 = p2->next;
        //让p1和p2同时移动，直到p2达到尾部
        while (p2->next != 0)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        
        //删除p1的下一个节点
        p1->next = p1->next->next;
        
        return sentinel->next;
    }
};