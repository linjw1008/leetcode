#include <vector>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0 && l1->next == NULL)
        {
            return l2;
        }
        else if (l2->val == 0 && l2->next == NULL)
        {
            return l1;
        }

        ListNode* ret = new ListNode(0);
        ListNode* l = ret;
        int flag = 0;

        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + flag;
            if (sum >= 10)
            {
                sum = sum - 10;
                flag = 1;
            }
            else
            {
                flag = 0;
            }

            l->next = new ListNode(sum);

            l = l->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                int sum = l2->val + flag;
                if (sum >= 10)
                {
                    sum = sum - 10;
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                l->next = new ListNode(sum);
                l = l->next;
                l2 = l2->next;
            }
        }
        else if (l2 == NULL)
        {
            while (l1 != NULL)
            {
                int sum = l1->val + flag;
                if (sum >= 10)
                {
                    sum = sum - 10;                    
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                l->next = new ListNode(sum);
                l = l->next;
                l1 = l1->next;
            }
        }

        if (flag == 1)
        {
            l->next = new ListNode(1);
        }
        
        return ret->next;
    }
};