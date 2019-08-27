#ifndef _PASCAL_S_TRIANGLE_SECOND_H_
#define _PASCAL_S_TRIANGLE_SECOND_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        int** record;
        record = new int*[rowIndex + 1];
        for (int i = 0; i < rowIndex + 1; i++)
            record[i] = new int[i + 1]();
        
        for (int i = 1; i <= rowIndex + 1; i++)
            ret.push_back(tri(rowIndex + 1, i, record));
            
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