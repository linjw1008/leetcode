#ifndef _SEARCH_IN_ROTATED_SORTED_ARRAY_V1_H_
#define _SEARCH_IN_ROTATED_SORTED_ARRAY_V1_H_

//搜索旋转排序数组
//二分法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;
        
        int rotate_index = serach_rotate_index(0, len - 1, nums);
        if (target <= nums[len - 1])
            return search(rotate_index, len - 1, nums, target);
        else
            return search(0, rotate_index - 1, nums, target);
    }

    int serach_rotate_index(int left, int right, vector<int>& nums)
    {
        if (nums[left] < nums[right])
            return 0;
        
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > nums[middle + 1])
                return middle + 1;
            else
            {
                if (nums[middle] < nums[left])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
        }
        return 0;
    }

    int search(int left, int right, vector<int>& nums, int target)
    {
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] == target)
                return middle;
            else
            {
                if (nums[middle] > target)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
        }
        return -1;
    }
};

#endif