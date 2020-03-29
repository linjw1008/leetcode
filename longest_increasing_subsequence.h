//最长上升子序列
//动态规划

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return len;
        }

        int res = 1;

        dp.resize(len, 1);

        for (int i = 1; i < len; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(res, dp[i]);
            }
        }
    
        return res;    
    }
};