//最佳买卖股票时机含冷冻期

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp;
        int lastBought = 0;
        int len = prices.size();
        dp.resize(len);
        for (int i = 0; i < len; i++)
        {
            dp[i].resize(3);
        }

        if (len <= 1)
        {
            return 0;
        }

        dp[0][0] = 0; //不买
        dp[0][1] = -prices[0]; //买
        dp[0][2] = 0; //冷冻期

        for (int i = 1; i < len; i++)
        {
            //i不持股，可以由持股、不持股转移而来
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //i持股，可以由持股、冷冻期转移而来
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            //i冷冻期，由不持股转移而来
            dp[i][2] = dp[i-1][0];
        }
        
        return max(max(dp[len - 1][0], dp[len - 1][1]), dp[len - 1][2]);
    }
};