//环形链表 II
//快慢指针法

#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        //首先找出相遇点，若无相遇点，则说明没有环
        while (fastPtr != nullptr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            if (fastPtr == nullptr)
            {
                return nullptr;
            }
            else
            {
                fastPtr = fastPtr->next;
            }
            if (fastPtr == slowPtr)
            {
                break;
            }
        }
        //相遇，说明有环，重置指针
        if (fastPtr == slowPtr)
        {
            fastPtr = head;
            //两个指针步长为1向前移动直到相遇
            while (fastPtr != slowPtr)
            {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
        }    

        return fastPtr;    
    }
};