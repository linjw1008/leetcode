//递归，二分法
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        return searchMatrixCore(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
    
    bool searchMatrixCore(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2)
    {        
        if (x1 > x2 || y1 > y2 || matrix[x1][y1] > target || matrix[x2][y2] < target)
        {
            return false;
        }
        
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        
        if (matrix[midX][midY] == target) return true;
        else if (matrix[midX][midY] < target)
        {
            return searchMatrixCore(matrix, target, midX + 1, midY + 1, x2, y2)
                || searchMatrixCore(matrix, target, x1, midY + 1, midX, y2)
                || searchMatrixCore(matrix, target, midX + 1, y1, x2, midY);
        }
        else
        {
            return searchMatrixCore(matrix, target, x1, y1, midX, midY)
                || searchMatrixCore(matrix, target, x1, midY + 1, midX, y2)
                || searchMatrixCore(matrix, target, midX + 1, y1, x2, midY);
        }
    }
};