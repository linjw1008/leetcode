#include "common.h"

class Solution {
public:
    string reverseWords(string s) {
        //原地算法
        int curIndex = 0;
        int i;
        for (i = 0; i < s.size();)
        {
            //先跳过空格
            while (s[i] == ' ' && i < s.size()) i++;
            if (i == s.size()) break;
            int start = curIndex;
            while (s[i] != ' ' && i < s.size())
                s[curIndex++] = s[i++];
            
            //翻转子串
            reverse(s.begin() + start, s.begin() + curIndex);
            
            if (curIndex < s.size())
                s[curIndex++] = ' ';
        }
        //清除末尾
        if (curIndex > 0 && s[curIndex - 1] == ' ') s.erase(s.begin() + curIndex - 1, s.end());
        else if (curIndex >= 0 && s[curIndex] == ' ') s.erase(s.begin() + curIndex, s.end());
        
        //翻转整个字符串
        reverse(s.begin(), s.end());
        
        return s;
    }
};