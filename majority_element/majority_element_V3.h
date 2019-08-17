#ifndef _MAJORITY_ELEMENT_V3_H_
#define _MAJORITY_ELEMENT_V3_H_

//求众数
//投票法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int ret = 0;
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if(count == 0)
                ret = nums[i];
            if(ret == nums[i])
                count++;
            else
                count--;
        }

        return ret;
    }
};

#endif