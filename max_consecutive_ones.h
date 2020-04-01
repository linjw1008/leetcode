#include "common.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curMax = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                curMax = 0;
            else
                curMax++;
            ans = max(curMax, ans);
        }
        return ans;
    }
};