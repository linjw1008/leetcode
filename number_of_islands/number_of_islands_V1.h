#ifndef _NUMBER_OF_ISLANDS_V1_H_
#define _NUMBER_OF_ISLANDS_V1_H_

//岛屿数量
//深度优先搜索
//递归实现

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int num = 0;

        for(int x = 0; x < grid.size(); x++)
        {
            for(int y = 0; y < grid[0].size(); y++)
            {
                if(grid[x][y] == '1')
                {
                    dfs(grid, x, y);
                    num++;
                }
            }
        }

        return num;
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        
        grid[x][y] = '0';
        if(x > 0 && grid[x - 1][y] == '1')
            if(grid[x - 1][y] == '1')
                dfs(grid, x - 1, y);
        if(y > 0)
            if(grid[x][y - 1] == '1')
                dfs(grid, x, y - 1);
        if(x < grid.size() - 1)
            if(grid[x + 1][y] == '1')
                dfs(grid, x + 1, y);
        if(y < grid[0].size() - 1)
            if(grid[x][y + 1] == '1')
                dfs(grid, x, y + 1);        
    }
};

#endif