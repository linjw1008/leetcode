#ifndef _NUMBER_OF_ISLANDS_V2_H_
#define _NUMBER_OF_ISLANDS_V2_H_

//岛屿数量
//并查集

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    parent.push_back(i * col + j);
                    count++;
                }
                else
                {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
        if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
        else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
        else {
            parent[rooty] = rootx; rank[rootx] += 1;
        }
        --count;
        }
    }


    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        if(col == 0) return 0;

        UnionFind uf(grid);
        int num = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    if(i - 1 >= 0 && grid[i - 1][j] == '1') uf.Union(i * col + j, (i - 1) * col + j);
                    if(j - 1 >= 0 && grid[i][j - 1] == '1') uf.Union(i * col + j, i * col + j - 1);
                    if(i + 1 < row && grid[i + 1][j] == '1') uf.Union(i * col + j, (i + 1) * col + j);
                    if(j + 1 < col && grid[i][j + 1] == '1') uf.Union(i * col + j, i * col + j + 1);
                }
            }
        }

        return uf.getCount();

    }
};

#endif