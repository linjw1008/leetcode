#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int x = board.size();
        int y = board[0].size();
        vector<vector<bool>> flag;
        flag.resize(x);

        for (int i = 0; i < x; i++)
        {
            flag[i].resize(y, false);
        }
        
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j, flag))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y, vector<vector<bool>>& visited)
    {
        if (!(x < board.size()) || !(y < board[0].size()) || x < 0 || y < 0 || visited[x][y]) return false;

        //标记被访问过
        visited[x][y] = true;
        
        if (index == word.size() - 1 && board[x][y] == word[index])
        {
            return true;
        }
        
        
        if (board[x][y] == word[index])
        {
            if (dfs(board, word, index + 1, x, y + 1, visited) ||
                dfs(board, word, index + 1, x, y - 1, visited) ||
                dfs(board, word, index + 1, x + 1, y, visited) ||
                dfs(board, word, index + 1, x - 1, y, visited) )
            {
                return true;
            }
        }
        
        visited[x][y] = false;
        
        return false;
    }
};