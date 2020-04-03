#include "common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        if (nums.size() == 1) return (nums[0] == target) ? (vector<int>{0, 0}) : (vector<int>{-1, -1});
        
        int left = 0, right = nums.size() - 1;
        vector<int> ans;
        int mid;
        //left
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] != target) return {-1,-1};
        ans.push_back(left);
        
        left = 0;
        right = nums.size() - 1;
        //right
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        if (nums[right] == target) ans.push_back(right);
        else ans.push_back(right - 1);

        return ans;
    }
};