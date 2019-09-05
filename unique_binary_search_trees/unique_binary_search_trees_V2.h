#ifndef _UNIQUE_BINARY_SEARCH_TREES_V2_H_
#define _UNIQUE_BINARY_SEARCH_TREES_V2_H_

//不同的二叉搜索树
//动态规划

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        }

        return dp[n];
    }
};

#endif