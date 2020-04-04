#include "common.h"

//直接用二分法找出临届下标
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int index = get_index(nums);
        if (index == -1) return binary_search(nums, target, 0, nums.size() - 1);
        else if (nums[0] <= target) return binary_search(nums, target, 0, index - 1);
        return binary_search(nums, target, index, nums.size() - 1);
    }

    int get_index(vector<int>& nums)
    {
        if (nums[0] < nums[nums.size() - 1]) return -1;
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) return mid + 1;
            else if (nums[left] <= nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
    
    int binary_search(vector<int>& nums, int target, int left, int right)
    {
        if (left == right)
            if (nums[left] == target) return left;
            else return -1;
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) return binary_search(nums, target, mid + 1, right);
        else if (nums[mid] > target) return binary_search(nums, target, left, mid - 1);
        else return mid;

        return -1;
    }
};