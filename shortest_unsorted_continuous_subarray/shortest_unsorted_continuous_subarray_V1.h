#ifndef _SHORTEST_UNSORTED_CONTINUOUS_SUBARRAY_V1_H_
#define _SHORTEST_UNSORTED_CONTINUOUS_SUBARRAY_V1_H_

//最短无序连续子数组
//暴力法 超时

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int left = len;
        int right = 0;

        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[i] > nums[j])
                {
                    left = min(left, i);
                    right = max(right, j);
                }
            }
        }


        return right - left < 0 ? 0 : right - left + 1;
    }
};

#endif