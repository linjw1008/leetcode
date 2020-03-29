#include "common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int xLen = matrix.size();
        if (xLen == 0) return ans;
        int yLen = matrix[0].size();
        
        int xBegin = 0, yBegin = 0;
        while (xLen > xBegin * 2 && yLen >  yBegin * 2)
        {
            int xEnd = xLen - xBegin - 1;
            int yEnd = yLen - yBegin - 1;
            //从左向右
            for (int i = yBegin; i <= yEnd; ++i)
            {
                ans.push_back(matrix[xBegin][i]);
            }
            //从上向下
            if (xBegin < xEnd)
            {
                for (int i = xBegin + 1; i <= xEnd; ++i)
                {
                    ans.push_back(matrix[i][yEnd]);
                }
            }
            //从右向左
            if (xBegin < xEnd && yBegin < yEnd)
            {
                for (int i = yEnd - 1; i >= yBegin; --i)
                {
                    ans.push_back(matrix[xEnd][i]);
                }
            }
            //从下向上
            if (xBegin < xEnd - 1 && yBegin < yEnd)
            {
                for (int i = xEnd - 1; i >= xBegin + 1; --i)
                {
                    ans.push_back(matrix[i][yBegin]);
                }
            }
            
            xBegin++;
            yBegin++;
        }
        
        return ans;
    }
};