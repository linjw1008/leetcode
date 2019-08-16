#ifndef _NUMBER_OF_ISLANDS_V3_H_
#define _NUMBER_OF_ISLANDS_V3_H_

//岛屿数量
//广度优先搜索
//队列实现
//超时

#include <iostream>
#include <vector>
#include <queue>

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
                    bfs(grid, x, y);
                    num++;
                }
            }
        }

        return num;
    }

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty())
        {
            pair<int, int> index = q.front();
            q.pop();
            grid[index.first][index.second] = '0';
            if(index.first - 1 >= 0 && grid[index.first - 1][index.second] == '1') q.push({index.first - 1, index.second});
            if(index.second - 1 >= 0 && grid[index.first][index.second - 1] == '1') q.push({index.first, index.second - 1});
            if(index.first + 1 < grid.size() && grid[index.first + 1][index.second] == '1') q.push({index.first + 1, index.second});
            if(index.second + 1 < grid[0].size() && grid[index.first][index.second + 1] == '1') q.push({index.first, index.second + 1});
        }
    }
};

#endif