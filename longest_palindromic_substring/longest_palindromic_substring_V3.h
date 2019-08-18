#ifndef _LONGEST_PALINDROMIC_SUBSTRING_V3_
#define _LONGEST_PALINDROMIC_SUBSTRING_V3_

//最长回文子串
//马拉车算法

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string sAppended = "#";
        int len = s.size();
        
        if(len == 1 || len == 0) return s;

        for(int i = 0; i < len; i++)
        {
            sAppended += s[i];
            sAppended += "#";
        }

        len = sAppended.size();
        int* L = new int[len]; 
        int center = 0;
        int maxRight = 0;
        int maxLen = 0;
        int maxCenter = 0;

        for(int i = 0; i < len; i++)
        {
            if(i < maxRight)
                L[i] = min(L[2 * center - i], maxRight - i);
            else
                L[i] = 1;

            while(i - L[i] >= 0 && i + L[i] < len && sAppended[i - L[i]] == sAppended[i + L[i]])
                L[i] = L[i] + 1;

            if(L[i] + i - 1 > maxRight)
            {
                maxRight = L[i] + i - 1;
                center = i;
            }
            if(maxLen <= L[i])
            {
                maxLen = L[i];
                maxCenter = i;
            }
        }

        return s.substr((maxCenter - maxLen + 1) / 2, maxLen - 1);
    }
};

#endif