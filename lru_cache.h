#include "common.h"

class LRUCache {

private:
    struct Node{
        int k;
        int v;
        Node* next;
        Node* pre;
        Node(int x, int y) : k(x), v(y), next(nullptr), pre(nullptr){}
    };    
    int cap;
    int count;
    unordered_map<int, Node*> m;
    Node *dumb , *tail;  
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        dumb = new Node(0, 0);
        tail = new Node(0, 0);
        dumb->next = tail;
        dumb->pre = NULL;
        tail->next = NULL;
        tail->pre = dumb;
    }
    
    int get(int key)
    {
        //找不到节点
        if (m.find(key) == m.end())
        {
            return -1;
        }
        
        Node *n = m[key];
        //调整该节点到头部
        update(n);
        
        return dumb->next->v;
    }
    
    void put(int key, int val)
    {
        //key存在,直接修改，并更新节点至头节点
        if (m.find(key) != m.end())
        {
            Node* n = m[key];
            n->v = val;
            //调整该节点到头部
            update(n);
            return;
        }
        
        //容量上限，删除最不常用节点，即尾结点
        if (count == cap)
        {
            //从map中删除元素
            m.erase(m.find(tail->pre->k));
            //更新尾结点
            tail->pre->pre->next = tail;
            tail->pre = tail->pre->pre;
        }
        else
            count++;
        
        //新的节点
        Node* n = new Node(key, val);
        //更新map
        m[n->k] = n;
        //插入该节点到头部
        update(n);
    }
    
    //更新节点到头部，每次访问节点时调用
    inline void update(Node* n)
    {
        if (n->next == NULL && n->pre == NULL)
        {
            n->pre = dumb;
            n->next = dumb->next;
            n->next->pre = n;
            n->pre->next = n;
        }
        else
        {
            n->pre->next = n->next;
            n->next->pre = n->pre;
            n->next = dumb->next;
            n->pre = dumb;
            dumb->next = n;
            n->next->pre = n;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */