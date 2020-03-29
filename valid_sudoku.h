//有效的数独

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowSet(9, vector<int>(9, 0));
        vector<vector<int>> colSet(9, vector<int>(9, 0));
        vector<vector<int>> boxSet(9, vector<int>(9, 0));
        
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int index = board[i][j] - '1';
                if (index > 8 || index < 0) continue;
                if (rowSet[i][index] > 0 ||
                    colSet[j][index] > 0 || 
                    boxSet[(i / 3) + (j / 3) * 3][index] > 0)
                return false;
                    rowSet[i][index] += 1;
                    colSet[j][index] += 1; 
                    boxSet[(i / 3) + (j / 3) * 3][index] += 1;
            }
        }
        
        return true;
    }    
};