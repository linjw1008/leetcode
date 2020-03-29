#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2)
        {
            return false;
        }
        int low = INT_MAX;
        int mid = INT_MAX;

        for (int i = 0; i < len; i++)
        {
            if (nums[i] > mid && mid > low)
            {
                return true;
            }
            else if (nums[i] <= mid && nums[i] > low)
            {
                mid = nums[i];
            }
            else if (nums[i] <= low)
            {
                low = nums[i];   
            }
        }
        
        return false;
    }
};