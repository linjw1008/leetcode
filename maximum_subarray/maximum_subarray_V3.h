#ifndef _MAXIMUM_SUBARRAY_V3_H_
#define _MAXIMUM_SUBARRAY_V3_H_

//最大子序和
//分治法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(vector<int>& nums, int left, int right)
    {
        if(left == right) return nums[left];

        int center = (left + right) / 2;

        int leftMax = maxSubArray(nums, left, center);
        int rightMax = maxSubArray(nums, center + 1, right);

        int leftAndRightMax = max(leftMax, rightMax);

        long leftSumMax = INT_MIN;
        long rightSumMax = INT_MIN;
        long leftSum = 0;
        long rightSum = 0;
        for(int i = center; i >= 0; i--)
        {
            leftSum = leftSum + nums[i];
            leftSumMax = max(leftSum, leftSumMax);
        }
        for(int i = center + 1; i < nums.size(); i++)
        {
            rightSum = rightSum + nums[i];
            rightSumMax = max(rightSum, rightSumMax);
        }

        return max(long(leftAndRightMax), rightSumMax + leftSumMax);
    }
};

#endif