//最佳买卖股票时机III
//动态规划法

#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp;
        int len = prices.size();
        dp.resize(len);

        if (len == 0)
        {
            return 0;
        }

        for (int i = 0; i < len; i++)
        {
            dp[i].resize(5);
        }
        
        dp[0][0] = 0;   //未买入股票
        dp[0][1] = -prices[0];  //第一次买入股票
        dp[0][2] = 0;   //第一次卖出股票
        dp[0][3] = INT_MIN;   //第二次买入股票
        dp[0][4] = 0;   //第二次卖出股票

        for (int i = 1; i < len; i++)
        {
            //没买入股票
            dp[i][0] = dp[i - 1][0];
            //第一次买入股票
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            //第一次卖出股票
            dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
            //第二次买入股票
            dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
            //第二次卖出股票
            dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
        }
        
        return max(dp[len - 1][0], max(dp[len - 1][2], dp[len - 1][4]));
    }
};