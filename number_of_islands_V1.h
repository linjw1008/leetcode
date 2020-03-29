#include <vector>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        int ret = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ret;
    }
    
    void dfs(vector<vector<char>>& grid, int m, int n)
    {
        grid[m][n] = '0';
        if (m > 0 && grid[m - 1][n] != '0') dfs(grid, m - 1, n);
        if (n > 0 && grid[m][n - 1] != '0') dfs(grid, m, n - 1);
        if (m < grid.size() - 1 && grid[m + 1][n] != '0') dfs(grid, m + 1, n);
        if (n < grid[0].size() - 1 && grid[m][n + 1] != '0') dfs(grid, m, n + 1);
    }
};