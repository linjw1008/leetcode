#ifndef _SWAP_NODES_IN_PAIRS_H_
#define _SWAP_NODES_IN_PAIRS_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct ListNode 
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

#endif