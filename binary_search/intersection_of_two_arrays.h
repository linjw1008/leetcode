#include "common.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //二分查找实现
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int pos = 0;
        
        while (pos < nums2.size())
        {
            if (binary_search(nums1, nums2[pos])) ans.push_back(nums2[pos]);
            //跳过重复数
            while (pos + 1 < nums2.size() && nums2[pos] == nums2[pos + 1]) pos++;
            pos++;
        }
        return ans;
    }
    
    bool binary_search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid +1;
            else right = mid - 1;
        }
        
        return false;
    }
};