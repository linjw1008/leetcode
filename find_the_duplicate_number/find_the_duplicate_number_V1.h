#ifndef _FIND_THE_DUPLICATE_NUMBER_V1_H_
#define _FIND_THE_DUPLICATE_NUMBER_V1_H_

//寻找重复数
//排序法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ret;

        for (int i = 0; i < len - 1; i++)
            if (nums[i] == nums[i + 1])
            {
                ret = nums[i];
                break;
            }

        return ret;    
    }
};

#endif