#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        
        return findPeakElement(nums, 0, nums.size() - 1);
        
    }
    
    int findPeakElement(vector<int>& nums, int left, int right)
    {
        if (left == right) return left;
        
        int mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1])
        {
            return findPeakElement(nums, mid + 1, right);
        }
        else
        {
            return findPeakElement(nums, left, mid);
        }
    }
};