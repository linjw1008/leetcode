#include "common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        rotate(nums, 0, len - k - 1);
        rotate(nums, len - k, len - 1);
        rotate(nums, 0, len - 1);
    }
    
    void rotate(vector<int>& nums, int left, int right)
    {
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++; right--;
        }
    }
};