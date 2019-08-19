#ifndef _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V3_H_
#define _FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_V3_H_

#include <iostream>
#include <vector>

//在排序数组中查找元素的第一个和最后一个位置
//二分查找
//直接用二分法找出左右边界

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return {-1, -1};
        
        int left = 0, right = len;
        int mid;
        int leftIndex = -1;
        int rightIndex = -1;

        //找出左边界
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] == target)
                right = mid;
        }
        leftIndex = right;
        //找出右边界
        left = 0;
        right = len;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] > target)
                right = mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] == target)
                left = mid + 1;
        }
        rightIndex = left - 1;

        if(rightIndex < leftIndex) return {-1, -1};
        
        return {leftIndex, rightIndex};
    }
};

#endif