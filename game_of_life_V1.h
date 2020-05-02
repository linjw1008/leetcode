#include "common.h"

class Solution {
public:
    vector<vector<int>> record;
    int height, width;
    
    int countAliveCeils(int x, int y)
    {
        int res = 0;
        if (x > 0 && record[x - 1][y] == 1) ++res;
        if (x < height - 1 && record[x + 1][y] == 1) ++res;
        if (y > 0 && record[x][y - 1] == 1) ++res;
        if (y < width - 1 && record[x][y + 1] == 1) ++res;
        if (x > 0 && y > 0 && record[x - 1][y - 1] == 1) ++res;
        if (x < height - 1 && y < width - 1 && record[x + 1][y + 1] == 1) ++res;
        if (x > 0 && y < width - 1 && record[x - 1][y + 1] == 1) ++res;
        if (x < height - 1 && y > 0 && record[x + 1][y - 1] == 1) ++res;
        
        return res;
    }
        
    void gameOfLife(vector<vector<int>>& board) {
        record = board;
        height = record.size();
        width = record[0].size();
        
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                //活细胞
                int count = countAliveCeils(i, j);
                if (record[i][j] == 1)
                {
                    if (count == 2 || count == 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
                else //死细胞
                {
                    if (count == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};