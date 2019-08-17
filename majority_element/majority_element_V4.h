#ifndef _MAJORITY_ELEMENT_V4_H_
#define _MAJORITY_ELEMENT_V4_H_

//求众数
//哈希表

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> counts;
        int ret = 0;
        int mid = len / 2;

        for(int i = 0; i < len; i++)
        {
            if(counts.count(nums[i]) == 0)
                counts[nums[i]] = 1;
            else
                counts[nums[i]] = counts[nums[i]] + 1;
        }

        for(auto c : counts)
            if(c.second > mid) ret =  c.first;

        return ret;
    }
};

#endif