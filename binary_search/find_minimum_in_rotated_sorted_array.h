#include "common.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if (nums[mid] < nums[left]) right = mid;
            else left = mid + 1;
        }
        return nums[0];
    }
};