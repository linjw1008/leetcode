#ifndef _SEARCH_A_2D_MATRIX_II_V1_H_
#define _SEARCH_A_2D_MATRIX_II_V1_H_

//搜索二维数组II
//双指针法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, y = 0;
        int row = matrix.size();
        int col = 0;
        if (row != 0) col = matrix[0].size();
        x = row - 1;

        while(x < row && y < col && y >= 0 && x >= 0)
        {
            if (matrix[x][y] < target) y++;
            else if (matrix[x][y] > target) x--;
            else if (matrix[x][y] == target) return true;            
        }

        return false;
    }
};

#endif