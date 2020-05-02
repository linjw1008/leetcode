#include "common.h"

class MyLinkedList {
public:
    struct node
    {
        int val;
        node* next;
        node(int val = 0) : val(val), next(NULL){}
    };
    struct node* head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0)
            return -1;
        
        struct node* node = head;
        while (node != NULL && index-- > 0)
            node = node->next;
        
        
        if (node == NULL)
            return -1;
        else
            return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        struct node* node = new struct node(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        struct node* node = new struct node(val);
        if (head == NULL)
            head = node;
        else
        {
            struct node* tail = head;
            while (tail->next != NULL)
                tail = tail->next;
            tail->next = node;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        struct node *node = new struct node(val);
        if (head == NULL)
            head = node;
        else if (index < 0)
        {
            node->next = head;
            head = node;
        }
        else if (index == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            //找到第index个节点
            struct node* prev = head;
            struct node* next = prev->next;
            //让prev指向第index-1个节点
            while (prev->next != NULL && --index > 0)
            {
                prev = prev->next;
                next = prev->next;
            }
            //大于链表长度
            if (index > 1)
                return;
            node->next = next;
            prev->next = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (head == NULL) return;
        if (index == 0)
            head = head->next;
        else
        {
            struct node* prev = head;
            struct node* next = prev->next;
            //将prev调整到要删除的节点之前
            while (prev->next != NULL && --index > 0)
            {
                prev = prev->next;
                next = prev->next;
            }
            //合法
            if (index == 0)
            {
                prev->next = next->next;
                next->next = NULL;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */