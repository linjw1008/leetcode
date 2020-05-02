#include "common.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        vector<int> ans(nums.size() - k + 1, 0);
        
        //dp记录以i为结尾的窗口的最大值的下标
        dp[k - 1] = 0;
        for (int i = 0; i < k; ++i)
            if (nums[i] >= nums[dp[k - 1]])
                dp[k - 1] = i;
        
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] >= nums[dp[i - 1]])
                dp[i] = i;
            else if (nums[i] < nums[dp[i - 1]] && dp[i - 1] >= i - k + 1)
                dp[i] = dp[i - 1];
            else
            {
                //重新定位dp
                dp[i] = i;
                for (int j = i; j >= i - k + 1; --j)
                    if (nums[j] >= nums[dp[i]])
                        dp[i] = j;
            }
        }
        
        for (int i = k - 1; i < dp.size(); ++i)
            ans[i - k + 1] = nums[dp[i]];
        
        return ans;
    }
};