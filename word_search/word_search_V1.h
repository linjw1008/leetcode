#ifndef _WORD_SEARCH_V1_H_
#define _WORD_SEARCH_V1_H_
//单词搜索
//DFS，回溯

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    bool res = dfs(board, visited, i, j, word, 0);
                    if(res) return true;
                }

            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string word, int index)
    {
        int row = board.size();
        int col = board[0].size();

        if(index == word.size()) return true;

        if(x < 0 || x >= row || y < 0 || y >= col || visited[x][y] || board[x][y] != word[index]) return false;

        visited[x][y] = true;

        if( dfs(board, visited, x - 1, y, word, index + 1) ||
            dfs(board, visited, x + 1, y, word, index + 1) ||
            dfs(board, visited, x, y - 1, word, index + 1) ||
            dfs(board, visited, x, y + 1, word, index + 1) )
            return true;
        else
        {
            visited[x][y] = false;
            return false;
        }
    }
};

#endif