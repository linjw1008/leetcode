//复制带随机指针的链表

#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        unordered_map<Node*, Node*> map;
        Node* ans = new Node(head->val);
        Node* ansPtr = ans;
        map[head] = ans;
        Node* headPtr = head;
        headPtr = headPtr->next;
        while (headPtr != NULL)
        {
            Node* node = new Node(headPtr->val);
            ansPtr->next = node;
            ansPtr = ansPtr->next;
            map[headPtr] = ansPtr;
            headPtr = headPtr->next;
        }
        
        headPtr = head;
        ansPtr = ans;
        
        while (headPtr != NULL)
        {
            if (headPtr->random != NULL)
            {
                ansPtr->random = map[headPtr->random];
            }
            headPtr = headPtr->next;
            ansPtr = ansPtr->next;
        }
        
        return ans;
    }
};