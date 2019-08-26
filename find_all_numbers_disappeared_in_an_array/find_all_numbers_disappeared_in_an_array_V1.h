#ifndef _FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_V1_H_
#define _FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_V1_H_

#include <iostream>
#include <vector>

using namespace std;

//找到所有数组中消失的数字
//桶排序
//使用额外空间

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        int *bucket = new int[len];
        vector<int> ret;
        memset(bucket, 0, len*sizeof(int));

        for (auto it : nums)
            bucket[it - 1] = bucket[it - 1] + 1;
        
        for (int i = 0; i < len; i++)
            if(bucket[i] == 0)
                ret.push_back(i + 1);

        return ret;
    }
};


#endif