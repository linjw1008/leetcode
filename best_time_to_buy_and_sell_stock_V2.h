//最佳买卖股票时机

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(3, vector<int>(len, 0));

        dp[0][0] = 0; //不操作
        dp[1][0] = -prices[0]; //第一次买
        dp[2][0] = 0; //第一次卖

        for (int i = 1; i < len; ++i)
        {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = max(dp[1][i - 1], -prices[i]);
            dp[2][i] = max(dp[2][i - 1], prices[i] + dp[1][i - 1]);
        }
        return dp[2][len - 1];
    }
};