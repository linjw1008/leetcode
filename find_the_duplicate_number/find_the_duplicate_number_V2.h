#ifndef _FIND_THE_DUPLICATE_NUMBER_V2_H_
#define _FIND_THE_DUPLICATE_NUMBER_V2_H_

//寻找重复数
//集合

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int ret;
        unordered_set<int> set;

        for (int i = 0; i < len; i++)
        {
            if (set.count(nums[i]) > 0)
            {
                ret = nums[i];
                break;
            }
            set.insert(nums[i]);        
        }

        return ret;    
    }
};

#endif