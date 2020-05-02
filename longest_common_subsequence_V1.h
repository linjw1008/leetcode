#include "common.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //动态规划
        int len1 = text1.size(), len2 = text2.size();
        if (len1 == 0 || len2 == 0) return 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                //若当前两个字符相等，则最长子序列为1+当前字符之前的两个字符串的子序列长度
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                //若不相等，则最长子序列为：包括当前字符的序列1与不包括当前字符的序列2的子序列长度，包括当前字符的序列2与不包括当前字符的序列1的子序列长度 两者最大值
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        } 

        return dp[len1][len2];
    }
};

