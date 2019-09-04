#ifndef _UNIQUE_PATHS_V1_H_
#define _UNIQUE_PATHS_V1_H_

//不同路径
//递归

#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int* memo = new int[m*n];
        memset(memo, 0, sizeof(int) * m * n);
        return uniquePaths(1, 1, m, n, memo);
    }

    int uniquePaths(int curX, int curY, int targetX, int targetY, int* memo) {
        if (memo[(curX - 1) + (curY - 1) * targetX] != 0)
            return memo[(curX - 1) + (curY - 1) * targetX];
        
        if (targetX == curX && targetY == curY)
            return 1;
        if (targetX == curX)
            return memo[(curX - 1) + (curY - 1) * targetX] = uniquePaths(curX, curY + 1, targetX, targetY, memo);
        if (targetY == curY)    
            return memo[(curX - 1) + (curY - 1) * targetX] = uniquePaths(curX + 1, curY, targetX, targetY, memo);
        return memo[(curX - 1) + (curY - 1) * targetX] = uniquePaths(curX + 1, curY, targetX, targetY, memo) + uniquePaths(curX, curY + 1, targetX, targetY, memo);
    }
};

#endif