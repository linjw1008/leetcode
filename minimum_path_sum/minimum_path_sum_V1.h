#ifndef _MINIMUM_PATH_SUM_V1_H_
#define _MINIMUM_PATH_SUM_V1_H_

//最小路径之和
//暴力递归
//超时

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum(grid, 0, 0);
    }

    int minPathSum(vector<vector<int>>& grid, int i, int j)
    {
        if(i == grid.size() || j == grid[0].size()) return INT_MAX;

        if(i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];

        return grid[i][j] + min(minPathSum(grid, i + 1, j), minPathSum(grid, i, j + 1));
    }
};

#endif