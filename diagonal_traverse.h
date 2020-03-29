#include "common.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        bool up = true;
        vector<int> ans;
        int xSize = matrix.size();
        if (xSize == 0) return ans;
        
        int ySize = matrix[0].size();
        int len = xSize + ySize - 1;
        ans.reserve(xSize * ySize);
        
        int x = 0, y = 0;
        for (int l = 0; l < len; ++l)
        {
            //向上
            if (up)
            {                
                while(1)
                {
                    ans.push_back(matrix[x][y]);
                    //判断是否走到末尾
                    if (x - 1 < 0 || y + 1 >= ySize) break;
                    x -= 1;
                    y += 1;
                }
                up = false;
                //指向下一个坐标
                if (y == ySize - 1)
                    x += 1;
                else
                    y += 1;
            }
            else  //向下
            {
                while(1)
                {
                    ans.push_back(matrix[x][y]);
                    //判断是否走到末尾
                    if (x + 1 >= xSize || y - 1 < 0) break;
                    x += 1;
                    y -= 1;
                }
                up = true;
                //指向下一个坐标
                if (x == xSize - 1)
                    y += 1;
                else
                    x += 1;
            }
        }
                
        return ans;
    }
};