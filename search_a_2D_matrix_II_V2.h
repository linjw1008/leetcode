//指针法
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int x = row - 1, y = 0;
        while (x >= 0 && x < row && y >=0 && y < col)
        {
            if (matrix[x][y] == target)
            {
                return true;
            }
            else if (matrix[x][y] > target)
            {
                x--;
            }
            else
            {
                y++;
            }
        }
        
        return false;
        
    }
};