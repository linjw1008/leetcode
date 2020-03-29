//买卖股票的最佳时机 IV

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();

        if (len == 0 || k == 0)
        {
            return 0;
        }

        vector<vector<int>> dp;
        dp.resize(len);
        k = k >= len / 2 + 1 ? len / 2 + 1 : k;
        for (int i = 0; i < len; i++)
        {
            dp[i].resize(2 * k + 1);
        }

        //未买入
        dp[0][0] = 0;
        //i奇数代表第i/2次买入，偶数代表第i/2次不买入
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 3; i < 2 * k + 1; i = i + 2)
        {
            dp[0][i] = INT_MIN;
            dp[0][i + 1] = 0;
        }

        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < 2 * k + 1; j = j + 2)
            {
                //持有j
                dp[i][j] = max(dp[i - 1][j - 1] - prices[i], dp[i - 1][j]);
                //不持有j+1
                dp[i][j + 1] = max(dp[i - 1][j] + prices[i], dp[i - 1][j + 1]);       
            }
        }

        int res = INT_MIN;

        for (int i = 0; i < 2 * k + 1; i = i + 2)
        {
            if (dp[len - 1][i] > res)
            {
                res = dp[len - 1][i];
            }
        }
        
        return res;
    }
};