#include "common.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        //方法2，统计字符数量
        vector<int> map(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        int i = 0;
        while (i < 26 && map[i++] == 0);
        
        return i == 26;
    }
};