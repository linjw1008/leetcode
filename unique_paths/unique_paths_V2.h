#ifndef _UNIQUE_PATHS_V2_H_
#define _UNIQUE_PATHS_V2_H_

//不同路径
//动态规划
//一维数组

#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int* dp = new int[m * n];
        memset(dp, 0, sizeof(int) * m * n);        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i + j * m] = 1;
                else if (i == 0)
                    dp[i + j * m] = dp[i + (j - 1) * m];
                else if (j == 0)
                    dp[i + j * m] = dp[(i - 1) + j * m];
                else
                    dp[i + j * m] = dp[i + (j - 1) * m] + dp[(i - 1) + j * m];
            }

        return dp[m * n - 1];   
    }
};

#endif