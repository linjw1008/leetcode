//最佳买卖股票时机III

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int MaxProfit(vector<int>& prices, int begin, int end) {
        if (begin > end)
        {
            return 0;
        }

        int len = end - begin + 1;
        int ret = 0;
        int minPrice = __INT_MAX__;

        for (int i = 0; i < len; i++)
        {
            if (minPrice > prices[i + begin])
            {
                minPrice = prices[i + begin];
            }
            else if (prices[i + begin] - minPrice > ret)
            {
                ret = prices[i + begin] - minPrice;
            }
        }
        
        return ret;
    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int len = prices.size();
        for (int i = 0; i < len; i++)
        {
            maxProfit = max(maxProfit, MaxProfit(prices, 0, i) + MaxProfit(prices, i + 1, len - 1));
        }
        return maxProfit;       
    }
};