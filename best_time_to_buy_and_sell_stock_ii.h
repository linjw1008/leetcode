//最佳买卖股票时机II

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;

        vector<int> dpCash, dpStock;
        dpCash.resize(len);
        dpStock.resize(len);

        dpCash[0] = 0;  //持有现金
        dpStock[0] = -prices[0]; //持有股票

        for (int i = 1; i < len; ++i)
        {
            //持有现金
            dpCash[i] = max(dpStock[i - 1] + prices[i], dpCash[i - 1]);
            //持有股票
            dpStock[i] = max(dpStock[i - 1], dpCash[i - 1] - prices[i]);
        }

        return dpCash[len - 1];
    }
};