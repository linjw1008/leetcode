#include "common.h"

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= 6; ++i)
            dp[1][i] = 1;
        
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6; ++k)
                    if (j - k >= 0)
                        dp[i][j] += dp[i - 1][j - k];
            }
        }

        double total = pow(6, n);
        vector<double> ans(6 * n - n + 1);
        for (int i = n; i <= 6 * n; ++i)
        {
            ans[i - n] = (double) dp[n][i] / total;
        }

        return ans;
    }
};