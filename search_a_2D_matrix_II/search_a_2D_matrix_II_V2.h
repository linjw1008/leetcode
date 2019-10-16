#ifndef _SEARCH_A_2D_MATRIX_II_V2_H_
#define _SEARCH_A_2D_MATRIX_II_V2_H_

//搜索二维数组II
//缩减搜索空间、递归法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> m;
    int t;

public:
    bool searchMatrix(int left, int up, int right, int down)
    {
        if (up > down || left > right) return false;
        else if (m[up][left] > t || m[down][right] < t) return false;
        int row = up;
        int col = left + (left - right) / 2;

        while (m[row][col] <= t && row <= down)
        {
            if(m[row][col] == t) return true;
            row++;
        }

        return searchMatrix(left, row, col - 1, down) || searchMatrix(col + 1, up, right, row - 1); 
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix;
        t = target;

        return searchMatrix(0, 0, m[0].size() - 1, m.size() - 1);
    }
};

#endif