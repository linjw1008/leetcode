#ifndef _LONGEST_PALINDROMIC_SUBSTRING_V1_
#define _LONGEST_PALINDROMIC_SUBSTRING_V1_

//最长回文子串
//动态规划

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        bool** dp;
        dp = new bool*[len];
        int ret[2] = {-1, -1};

        if(len == 1 || len == 0) return s;

        for(int i = 0; i < len; i++)
            dp[i] = new bool[len];
        
        for(int i = len - 1; i >= 0; i--)
        {
            for(int j = i; j < len; j++)
            {
                if(i == j)
                    dp[i][j] = true;
                else if(s[i] == s[j] && j - i == 1)
                    dp[i][j] = true;
                else if(j - i >= 2)
                    if(s[i] == s[j] && dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                else
                    dp[i][j] = false;
                if(dp[i][j] == true && (j - i) >= ret[1] - ret[0])
                {
                    ret[0] = i;
                    ret[1] = j;
                }                    
            }
        }

        return s.substr(ret[0], ret[1] - ret[0] + 1);
    }
};

#endif