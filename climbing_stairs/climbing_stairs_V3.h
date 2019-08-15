#ifndef _CLIMBING_STAIRS_V3_H_
#define _CLIMBING_STAIRS_V3_H_

//爬楼梯
//动态规划、记忆化递归
//减小时间复杂度至n


#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* memo = new int[n + 1];
        return climbStairs(n, memo);
    }

    int climbStairs(int n, int* memo)
    {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(memo[n] > 0) return memo[n];
        
        memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);

        return memo[n];
    }
};

#endif