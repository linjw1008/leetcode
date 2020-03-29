#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        
        vector<int> ret = {-1, -1};
        
        int left = 0, right = nums.size() - 1;
        int mid;
        //find the left index
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                if(mid == 0 || nums[mid - 1] < target) ret[0] = mid;
            }
            
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        
        left = 0; right = nums.size() - 1;
        //find the right index
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target) 
            {
                if (mid == nums.size() - 1 || nums[mid + 1] > target) ret[1] = mid;
            }
            
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        
        
        return ret;
    }
};