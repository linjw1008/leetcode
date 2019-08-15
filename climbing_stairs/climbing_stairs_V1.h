#ifndef _CLIMBING_STAIRS_V1_H_
#define _CLIMBING_STAIRS_V1_H_

//爬楼梯
//动态规划、递归
//超时


#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

#endif