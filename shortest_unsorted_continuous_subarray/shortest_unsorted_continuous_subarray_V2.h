#ifndef _SHORTEST_UNSORTED_CONTINUOUS_SUBARRAY_V2_H_
#define _SHORTEST_UNSORTED_CONTINUOUS_SUBARRAY_V2_H_

//最短无序连续子数组
//不适用额外空间

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int MIN = INT_MAX;
        int MAX = INT_MIN;
        int left = len;
        int right = 0;
        bool flag = false;

        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                MIN = min(MIN, nums[i + 1]);
        }
        flag = false;
        for (int i = len - 1; i > 0; i--)
        {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                MAX = max(MAX, nums[i - 1]);
        }
        
        for (int i = 0; i < len; i++)
        {
            if (MIN < nums[i])
            {
                left = i;
                break;
            }
        }

        for (int i = len - 1; i >= 0; i--)
        {
            if (MAX > nums[i])
            {
                right = i;
                break;
            }    
        }


        return right - left < 0 ? 0 : right - left + 1;
    }
};

#endif