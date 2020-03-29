//同构字符串

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> exist;
        if (s.size() != t.size()) return false;
        
        for (int i = 0; i < s.size(); ++i)
        {
            //map中未找到，加入map
            if (map.find(s[i]) == map.end())
            {
                map[s[i]] = t[i];
                if (exist.find(t[i]) != exist.end()) return false;
                else exist.insert(t[i]);
            }
            else if (map[s[i]] != t[i])
            {
                return false;
            }
        }
        
        return true;
    }
};