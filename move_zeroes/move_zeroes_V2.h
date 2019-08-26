#ifndef _MOVE_ZEROS_V2_H_
#define _MOVE_ZEROS_V2_H_

//移动零
//双指针法(优化)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int curPtr = 0;
        int nonZeroPtr = 0;

        for (; curPtr < len; curPtr++)
            if(nums[curPtr] != 0)
                swap(nums[curPtr], nums[nonZeroPtr++]);
    }
};

#endif