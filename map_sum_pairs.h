
#include "common.h"

class MapSum {
private:
    vector<MapSum*> children;
    int value;
public:
    /** Initialize your data structure here. */
    MapSum() {
        children.resize(26, NULL);
        value = 0;
    }
    
    void insert(string key, int val) {
        MapSum *node = this;
        for (auto &k : key)
        {
            if (node->children[k - 'a'] == NULL) node->children[k - 'a'] = new MapSum();
            node = node->children[k - 'a'];
        }
        node->value = val;
    }
    
    int sum(string prefix) {
        //先找到前缀
        MapSum *node = this;
        for (auto &p : prefix)
        {
            //若前缀不存在直接返回0
            if (node->children[p - 'a'] == NULL) return 0;
            node = node->children[p - 'a'];
        }
        //对前缀进行dfs，求出所有键的和
        return dfs(node);
    }
    
    int dfs(MapSum *node)
    {
        if (node == NULL) return 0;
        int ans = node->value;
        for (int i = 0; i < 26; ++i)
            ans += dfs(node->children[i]);
        
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */