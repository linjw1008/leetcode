//设计哈希表
#include <vector>
#include <list>

using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> map;
    int len = 1000;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(len);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % len;
        auto &m = map[index];
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->first == key)
            {
                it->second = value;
                return;
            }
        }
        m.push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % len;
        auto &m = map[index];
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->first == key) return it->second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % len;
        auto &m = map[index];
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->first == key)
            {
                m.erase(it);
                break;
            }
        }
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */