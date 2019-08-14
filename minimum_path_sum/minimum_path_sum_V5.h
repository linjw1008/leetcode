#ifndef _MINIMUM_PATH_SUM_V5_H_
#define _MINIMUM_PATH_SUM_V5_H_

//最小路径之和
//二维动态规划
//从左上角开始

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int** dp;
        dp = new int* [row];
        for(int i = 0; i < row; i++)
        {
            dp[i] = new int[col];
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(i == 0 && j != 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if(i != 0 && j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else if(i != 0 && j != 0)
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = grid[i][j];
                
            }
        }

        return dp[row - 1][col - 1];
    }
};

#endif