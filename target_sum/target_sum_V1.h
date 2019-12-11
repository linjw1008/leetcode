#ifndef _TARGET_SUM_V1_H_
#define _TARGET_SUM_V1_H_

//目标和
//动态规划

#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        int** dp = new int*[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = new int[2001];
            memset(dp[i], 0, 2001 * sizeof(int));
        }


        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;

        for (int i = 1; i < len; i++)
        {
            for (int sum = -1000; sum <= 1000; sum++)
            {
                if (dp[i - 1][sum + 1000] > 0)
                {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        
        return S > 1000 ? 0 : dp[len - 1][S + 1000];        
    }
};

#endif