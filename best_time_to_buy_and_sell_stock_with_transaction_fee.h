//买卖股票的最佳时机含手续费

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len == 0)
        {
            return 0;
        }

        int** dp;
        dp = new int*[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = new int[2];
        }
        
        dp[0][0] = 0;   //不持有股票
        dp[0][1] = -prices[0];    //持有股票

        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - fee + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        
        return dp[len - 1][0];
    }
};