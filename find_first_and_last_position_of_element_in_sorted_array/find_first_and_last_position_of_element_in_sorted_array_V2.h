#ifndef _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V2_H_
#define _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V2_H_

#include <iostream>
#include <vector>

//在排序数组中查找元素的第一个和最后一个位置
//二分查找
//用二分查找找到某一个target后，向左向右分别遍历到边界

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid;
        int i, j;

        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else 
            {        
                for(i = mid; i < len && nums[i] == target; i++);
                for(j = mid; j >= 0 && nums[j] == target; j--);
                ret[0] = j + 1;
                ret[1] = i - 1;
                break;
            }
        }

        return ret;
    }
};

#endif