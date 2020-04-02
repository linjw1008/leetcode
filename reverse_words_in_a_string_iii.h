#include "common.h"

class Solution {
public:
    string reverseWords(string s) {
        //原地算法
        for (int i = 0; i < s.size(); )
        {
            //跳过空格
            while (s[i] == ' ' && i < s.size()) i++;
            int start = i;
            //跳过字符，找到当前单词的末尾
            while (s[i] != ' ' && i < s.size()) i++;
            reverse(s.begin() + start, s.begin() + i);
        }
        
        return s;
    }
};