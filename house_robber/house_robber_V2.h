#ifndef _HOUSE_ROBBER_V2_H
#define _HOUSE_ROBBER_V2_H

//打家劫舍
//动态规划
//空间复杂度O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int prevMax = 0;
        int currMax = 0;

        if (len == 1)
            return nums[0];
        
        if (len == 0)
            return 0;
        
        for(auto x : nums)
        {
            int tmp = currMax;
            currMax = max(prevMax + x, currMax);
            prevMax = tmp;
        }

        return currMax;
    }
};

#endif