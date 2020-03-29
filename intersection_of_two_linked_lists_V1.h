//相交链表

//哈希表法

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
        unordered_map<ListNode*, int> map;
        int index = 0;

        while (headA != nullptr)
        {
            map.insert({headA, index});
            headA = headA->next;
            index++;
        }
        
        while (headB != nullptr)
        {
            if (map.find(headB) != map.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        
        return nullptr;
    }
};