//最佳买卖股票时机

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPricce = __INT_MAX__;
        int ret = 0;
        int len = prices.size();

        for (int i = 0; i < len; i++)
        {
            if (prices[i] < minPricce)
            {
                minPricce = prices[i];
            }
            else if (prices[i] - minPricce > ret)
            {
                ret = prices[i] - minPricce;
            }
        }

        return ret;
    }
};