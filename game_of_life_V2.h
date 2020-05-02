#include "common.h"

//原地算法
//利用一个int有32位，最低1位存储细胞的原状态
//，倒数第二位储存细胞的更新状态

class Solution {
public:
    int height, width;
    
    int countAliveCeils(vector<vector<int>>& board, int x, int y)
    {
        int res = 0;
        if (x > 0 && board[x - 1][y] & 1) ++res;
        if (x < height - 1 && board[x + 1][y] & 1) ++res;
        if (y > 0 && board[x][y - 1] & 1) ++res;
        if (y < width - 1 && board[x][y + 1] & 1) ++res;
        if (x > 0 && y > 0 && board[x - 1][y - 1] & 1) ++res;
        if (x < height - 1 && y < width - 1 && board[x + 1][y + 1] & 1) ++res;
        if (x > 0 && y < width - 1 && board[x - 1][y + 1] & 1) ++res;
        if (x < height - 1 && y > 0 && board[x + 1][y - 1] & 1) ++res;
        
        return res;
    }
        
    void gameOfLife(vector<vector<int>>& board) {
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                //活细胞
                int count = countAliveCeils(board, i, j);
                if (board[i][j] == 1)
                {
                    if (count == 2 || count == 3)
                        board[i][j] |= 2;
                    else
                        board[i][j] |= 0;
                }
                else //死细胞
                {
                    if (count == 3)
                        board[i][j] |= 2;
                }
            }
        }
        
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                board[i][j] = board[i][j] >> 1;
        
    }
};