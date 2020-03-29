//相交链表

//双指针法

#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        
        ListNode* pA = headA, *pB = headB;

        while (1)
        {
            if (pA == pB)
            {
                return pA;
            }
            
            if (pA->next == nullptr && pB->next == nullptr)
            {
                break;
            }
            else
            {
                if (pA->next == nullptr)
                {
                    pA = headB;
                    pB = pB->next;
                }
                else if (pB->next == nullptr)
                {
                    pB = headA;
                    pA = pA->next;
                }
                else
                {
                    pA = pA->next;
                    pB = pB->next;
                }
            }
        }
        
        return nullptr;

    }
};