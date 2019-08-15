#ifndef _CLIMBING_STAIRS_V2_H_
#define _CLIMBING_STAIRS_V2_H_

//爬楼梯
//动态规划、dp数组

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* dp;
        dp = new int[n + 1];
        if(n == 1) return 1;

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

#endif