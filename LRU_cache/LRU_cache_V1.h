#ifndef _LRU_CACHE_V1_H_
#define _LRU_CACHE_V1_H_

//LRU缓存机制
//哈希链表

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        //key不存在
        if(it == map.end()) return -1;
        //key存在，将其调换到链表头
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        map[key] = cache.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        //已存在
        if(it != map.end())
        {
            cache.erase(map[key]);
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
        else //不存在
        {
            //已满
            if(cache.size() == capacity)
            {
                auto tail = cache.back();
                int tailKey = tail.first;
                cache.pop_back();
                map.erase(tailKey);
            }
            pair<int, int> kv = {key, value};
            cache.push_front(kv);
            map[key] = cache.begin();
        }
    }

private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};


#endif