//哈希表

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        cout << "len " << len << endl;
        int ret = 0;
        int count_tmp = 0;
        int index = 0;
        map<char, int> char_map;

        int i = 0;
        for(i = 0; i < len; i++)
        {
            if(char_map.count(s[i]) > 0 && char_map[s[i]] >= index )
            {
                count_tmp = i - char_map[s[i]];
                index = char_map[s[i]] + 1;
                char_map[s[i]] = i;
                continue;
            }
            count_tmp++;
            char_map[s[i]] = i;
            if(count_tmp > ret) ret = count_tmp;
        }

        return ret;
    }
};