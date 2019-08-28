#ifndef _MAXIMUM_PRODUCT_SUBARRAY_V1_H_
#define _MAXIMUM_PRODUCT_SUBARRAY_V1_H_

//乘积最大子序列
//动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int cur_max = 1;
        int cur_min = 1;
        int ret = INT_MIN;
        
        for (int i = 0; i < len; i++)
        {
            int tmp = cur_max;
            cur_max = max(nums[i], max(cur_max * nums[i], cur_min * nums[i]));
            cur_min = min(nums[i], min(cur_min * nums[i], tmp * nums[i]));
            ret = max(cur_max, ret);
        }

        return ret;
    }
};

#elif