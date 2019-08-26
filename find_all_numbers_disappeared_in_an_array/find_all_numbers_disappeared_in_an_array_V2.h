#ifndef _FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_V2_H_
#define _FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_V2_H_

#include <iostream>
#include <vector>

using namespace std;

//找到所有数组中消失的数字
//“映射法”
//不使用额外空间

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;

        for (auto it : nums)
            nums[abs(it) - 1] = -abs(nums[abs(it) - 1]);
        
        for (int i = 0; i < len; i++)
            if(nums[i] > 0)
                ret.push_back(i + 1);

        return ret;
    }
};

#endif