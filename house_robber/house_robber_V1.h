#ifndef _HOUSE_ROBBER_V1_H
#define _HOUSE_ROBBER_V1_H

//打家劫舍
//动态规划
//空间复杂度O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int* dp = new int[len];
        int ret = 0;

        if (len == 1)
            return nums[0];
        
        if (len == 0)
            return 0;
        
        if (len == 2)
            return max(nums[0], nums[1]);
        

        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i = 2; i < len; i++)
            dp[i] = max(dp[i - 2] +  nums[i], dp[i - 1]);

        return dp[len - 1];
    }
};

#endif