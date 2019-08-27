#ifndef _PASCAL_S_TRIANGLE_H_
#define _PASCAL_S_TRIANGLE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        int** record;
        record = new int*[numRows];
        for (int i = 0; i < numRows; i++)
            record[i] = new int[i + 1]();
        
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> tmp;
            for (int j = 1; j <= i; j++)
                tmp.push_back(tri(i, j, record));
            ret.push_back(tmp);
        }
            
        return ret;    
    }

    int tri(int i, int j, int** record)
    {
        if (record[i - 1][j - 1] != 0)
            return record[i - 1][j - 1];

        if (j == 1 || i == j)
        {
            record[i - 1][j - 1] = 1;
            return 1;
        }
        else
        {
            record[i - 1][j - 1] = tri(i - 1, j - 1, record) + tri(i - 1, j, record);
            return record[i - 1][j - 1];
        }
            
    }
};

#endif