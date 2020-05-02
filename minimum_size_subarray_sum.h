#include "common.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //滑动窗口
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        while (left <= (int)nums.size() - 1)
        {
            if (right < nums.size() && sum < s)
                sum += nums[right++];
            else
                sum -= nums[left++];
            
            if (sum >= s)
                ans = min(ans, right - left);
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};