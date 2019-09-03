#ifndef _PERFECT_SQUARES_V2_H_
#define _PERFECT_SQUARES_V2_H_

//完全平方数
//暴力递归

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int* memo = new int[n + 1];
        memset(memo, 0, sizeof(int) * (n + 1));
        return numSquares(n, memo);
    }
    int numSquares(int n, int* memo)
    {
        if (n == 0)
            return 0;
        int ret = INT_MAX;
        if (memo[n] != 0)
            return memo[n];
        for (int i = 1; n - i * i >= 0; i++)
        {
            int tmp = numSquares(n - i * i, memo);
            ret = (ret < (tmp + 1)) ? ret : (tmp + 1);
        }
        memo[n] = ret;
        return memo[n];
    }
};

#endif