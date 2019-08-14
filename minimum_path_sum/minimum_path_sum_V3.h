#ifndef _MINIMUM_PATH_SUM_V3_H_
#define _MINIMUM_PATH_SUM_V3_H_

//最小路径之和
//一维动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        //vector<int> dp(col, 0);
        int *dp;
        dp = new int[col];

        for(int i = row - 1; i >= 0; i--)
        {
            for(int j = col - 1; j >= 0; j--)
            {
                if(i == row - 1 && j != col - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if(i != row - 1 && j == col - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if(i != row - 1 && j != col - 1)
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
                
            }
        }

        return dp[0];
    }
};

#endif