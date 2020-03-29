#include "common.h"

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int secondMax = -1;
        int firstMax = -1;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (firstMax < nums[i])
            {
                firstMax = nums[i];
                ans = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
            if (secondMax < nums[i] && nums[i] < firstMax)
                secondMax = nums[i];
        
        return (secondMax <= firstMax/2) ? ans : -1;
    }
};