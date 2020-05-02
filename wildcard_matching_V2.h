#include "common.h"

//动态规划法
//https://leetcode-cn.com/problems/wildcard-matching/solution/dong-tai-gui-hua-dai-zhu-shi-by-tangweiqun/

class Solution {
public:
    bool isMatch(string s, string p) {
        string p1;
        int index = 0, i = 0;
        while (i < p.size())
        {
            if (p[i] == '*')
            {
                p1.push_back(p[i]);
                //跳过剩余的*
                while (i < p.size() && p[i] == '*')
                    i++;
            }
            else
            {
                p1.push_back(p[i]);
                i++;
            }
        }
        
        p = p1;
        if (p == s)
            return true;
        if (s.size() == 0 && p != "*")
            return false;
        if (p == "*")
            return true;
        
        //动态规划
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true;
        
        if (p[0] == '*')
            dp[1][0] = true;
        
        for (int i = 0; i < p.size(); ++i)
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[j] == p[i] || p[i] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                //dp[i][j + 1]代表不要当前的*，因此忽略掉*
                //dp[i + 1][j]代表要当前的*，由于*匹配任意字符，因此忽略掉当前的字符，即忽略掉j + 1对应的字符
                else if (p[i] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
            }
        }
        return dp[p.size()][s.size()];
    }
};