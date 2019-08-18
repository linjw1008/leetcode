#ifndef _LONGEST_PALINDROMIC_SUBSTRING_V2_
#define _LONGEST_PALINDROMIC_SUBSTRING_V2_

//最长回文子串
//中心扩展算法

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0 || len == 1)return s;
        int l = 0, r = 0;

        for(int i = 0; i < len; i++)
        {
            int len1 = expandAroundCenter(s, i, i + 1);
            int len2 = expandAroundCenter(s, i, i);

            int len = max(len1, len2);

            if(len > r - l)
            {
                l = i - (len - 1) / 2;
                r = i + len / 2;
            }
        }

        return s.substr(l, r - l + 1);        
    }

    int expandAroundCenter(string& s, int lptr, int rptr)
    {
        int l = lptr, r = rptr;
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }

        return r - l - 1;
    }
};

#endif