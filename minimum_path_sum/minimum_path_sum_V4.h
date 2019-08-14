#ifndef _MINIMUM_PATH_SUM_V4_H_
#define _MINIMUM_PATH_SUM_V4_H_

//最小路径之和
//二维动态规划
//不使用额外空间

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = row - 1; i >= 0; i--)
        {
            for(int j = col - 1; j >= 0; j--)
            {
                if(i == row - 1 && j != col - 1)
                    grid[i][j] = grid[i][j] + grid[i][j + 1];
                else if(i != row - 1 && j == col - 1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];
                else if(i != row - 1 && j != col - 1)
                    grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
                else
                    grid[i][j] = grid[i][j];
                
            }
        }

        return grid[0][0];
    }
};

#endif