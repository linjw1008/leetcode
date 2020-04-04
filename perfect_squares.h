#include "common.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        int i = 0;
        //完全平方数自身的个数为1
        while (i * i <= n)
        {
            dp[i * i] = 1;
            i++;
        }
        int k = 1;
        for (int i = 1; i <= n; ++i)
        {
            //本身就是完全平方数，跳过
            if (dp[i] == 1) continue;
            
            int j = 1;
            while (j * j <= i)
            {
                dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
                j++;
            }
        }
        
        return dp[n];
    }
};