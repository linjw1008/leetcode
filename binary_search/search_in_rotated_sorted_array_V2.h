#include "common.h"

//先在有序的子序列中进行判断

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        return binary_search(nums, target, 0, nums.size() - 1);
    }
    
    int binary_search(vector<int>& nums, int target, int left, int right)
    {
        if (left == right)
            if (nums[left] == target) return left;
            else return -1;
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        
        if (nums[left] <= nums[mid]) //左边升序
        {
            if (nums[left] <= target && target < nums[mid]) //在左边查找
                return binary_search(nums, target, left, mid - 1);
            else return binary_search(nums, target, mid + 1, right);
        }
        else //右边升序
        {
            if (nums[mid] < target && target <= nums[right]) //在右边查找
                return binary_search(nums, target, mid + 1, right);
            else return binary_search(nums, target, left, mid - 1);
        }
        
        return -1;
    }
};