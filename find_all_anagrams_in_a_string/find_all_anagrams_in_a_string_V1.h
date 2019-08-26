#ifndef _FIND_ALL_ANAGRAMS_IN_A_STRING_V1_H_
#define _FIND_ALL_ANAGRAMS_IN_A_STRING_V1_H_

#include <iostream>
#include <vector>

using namespace std;

//找到字符串中所有字母异位词
//双指针、滑动窗口

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;

        if (s.empty() || s.size() < p.size())
            return ret;
        
        int len = s.size();
        int left = 0;
        int right = p.size() - 1;
        int freqS[26] = {0};
        int freqP[26] = {0};

        for (int i = 0; i < p.size(); i++)
        {
            freqS[s[i] - 'a']++;
            freqP[p[i] - 'a']++;
        }

        for (; right < len; left++, right++)
        {
            int i;
            for (i = 0; i < 26; i++)
                if (freqS[i] != freqP[i])
                    break;
            if (i == 26)
                ret.push_back(left);
            if (right + 1 == s.size())
                return ret;
            freqS[s[left] - 'a']--;
            freqS[s[right + 1] - 'a']++;
        }

        return ret;
    }
};

#endif