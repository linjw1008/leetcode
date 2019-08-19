#ifndef _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V1_H_
#define _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V1_H_

#include <iostream>
#include <vector>

//在排序数组中查找元素的第一个和最后一个位置
//线性扫描

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int len = nums.size();
        int i, j;

        for(i = 0; i < len; i++)
        {
            if(nums[i] == target)
            {
                ret[0] = i;
                break;
            }
        }

        for(j = len - 1; j >= i; j--)
        {
            if(nums[j] == target)
            {
                ret[1] = j;
                break;
            }
        }

        return ret;
    }
};

#endif