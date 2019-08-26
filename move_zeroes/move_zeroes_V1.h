#ifndef _MOVE_ZEROS_V1_H_
#define _MOVE_ZEROS_V1_H_

//移动零
//双指针法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int curPtr = 0;
        int nonZeroPtr = 0;

        for (; nonZeroPtr < len; nonZeroPtr++)
        {
            if(nums[nonZeroPtr] != 0)
                nums[curPtr++] = nums[nonZeroPtr];
        }

        for (; curPtr < len; curPtr++)
            nums[curPtr] = 0;
    }
};

#endif