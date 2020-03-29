#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* p = head;
        ListNode* even = p->next;


        while (even->next != nullptr)
        {
            ListNode* tmpLeft = p->next;
            ListNode* tmpRight = even->next;
            even->next = tmpRight->next;
            p->next = tmpRight;
            tmpRight->next = tmpLeft;

            p = p->next;
            even = even->next;

            if (even == nullptr)
            {
                break;
            }
        }

        return head;
    }
};