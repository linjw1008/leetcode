#ifndef _MAJORITY_ELEMENT_V1_H_
#define _MAJORITY_ELEMENT_V1_H_

//求众数
//排序

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

#endif