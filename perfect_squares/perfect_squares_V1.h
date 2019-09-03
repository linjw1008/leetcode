#ifndef _PERFECT_SQUARES_V1_H_
#define _PERFECT_SQUARES_V1_H_

//完全平方数
//动态规划、自底向上

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int* dp = new int[n + 1];
        memset(dp, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};

#endif