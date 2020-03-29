#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        queue<pair<int, int>> q;
        
        int ret = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ret++;
                    q.push({i, j});
                    
                    grid[i][j] = '0';
                    
                    while(!q.empty())
                    {
                        auto index = q.front();
                        q.pop();
                        int x = index.first, y = index.second;
                        if (x > 0 && grid[x - 1][y] == '1') {q.push({x - 1, y}); grid[x - 1][y] = '0';};
                        if (y > 0 && grid[x][y - 1] == '1') {q.push({x, y - 1}); grid[x][y - 1] = '0';};
                        if (x < m - 1 && grid[x + 1][y] == '1') {q.push({x + 1, y}); grid[x + 1][y] = '0';};
                        if (y < n - 1 && grid[x][y + 1] == '1') {q.push({x, y + 1}); grid[x][y + 1] = '0';};
                    }
                }
            }
        }
        
        
        return ret;
    }
};