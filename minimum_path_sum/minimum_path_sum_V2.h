#ifndef _MINIMUM_PATH_SUM_V2_H_
#define _MINIMUM_PATH_SUM_V2_H_

//最小路径之和
//二维动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        //vector<vector<int>> dp(row, vector<int>(col, 0));
        int** dp;
        dp = new int*[row];
        for(int i = 0; i < row; i++)
        {
            dp[i] = new int[col];
        }


        for(int i = row - 1; i >= 0; i--)
        {
            for(int j = col - 1; j >= 0; j--)
            {
                if(i == row - 1 && j != col - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if(i != row - 1 && j == col - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if(i != row - 1 && j != col - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
                
            }
        }

        return dp[0][0];
    }
};

#endif