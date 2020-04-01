#include "common.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int sum = 0;
        for (right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= s)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};