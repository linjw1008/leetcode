#ifndef _UNIQUE_BINARY_SEARCH_TREES_V1_H_
#define _UNIQUE_BINARY_SEARCH_TREES_V1_H_

//不同的二叉搜索树
//分治法、递归实现

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* memo = new int[n];
        memset(memo, 0, sizeof(int) * n);
        return numTrees(1, n, memo);
    }

    int numTrees(int lptr, int rptr, int* memo)
    {
        if (memo[rptr - lptr] != 0)
            return memo[rptr - lptr];
        
        if (lptr == rptr)
            return memo[0] = 1;
        int pathNum = 0;
        for (int i = lptr; i <= rptr; i++)
        {
            if (i == lptr)
                pathNum += numTrees(i + 1, rptr, memo);
            else if (i == rptr)
                pathNum += numTrees(lptr, i - 1, memo);
            else
                pathNum += numTrees(i + 1, rptr, memo) * numTrees(lptr, i - 1, memo);
        }

        return memo[rptr - lptr] = pathNum;        
    }
};

#endif