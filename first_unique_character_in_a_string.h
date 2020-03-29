//字符串中的第一个唯一字符

#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map(26, 0);
        
        //建立哈希表
        for (int i = 0; i < s.size(); ++i)
        {
            map[s[i] - 'a']++;
        }
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (map[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};