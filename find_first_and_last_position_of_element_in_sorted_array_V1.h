#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        
        vector<int> ret = {-1, -1};
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        if (nums[mid] == target)
        {
            left = mid;
            right = mid;
        
            while (left >= 0 && nums[left] == target) left--;
            while (right < nums.size() && nums[right] == target) right++;
            
            ret = {left + 1, right - 1};
        }
        
        return ret;
    }
};