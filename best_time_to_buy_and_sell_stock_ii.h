//最佳买卖股票时机II

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        if (len == 0)
        {
            return 0;
        }

        vector<int> dpBought, dpNotBought;
        dpBought.resize(len);
        dpNotBought.resize(len);

        dpBought[0] = -prices[0];
        dpNotBought[0] = 0;

        for (int i = 1; i < len; i++)
        {
            //持有i
            dpBought[i] = max(dpNotBought[i - 1] - prices[i], dpBought[i - 1]);
            //不持有i
            dpNotBought[i] = max(dpBought[i - 1] + prices[i], dpNotBought[i - 1]);
        }
        
        return max(dpNotBought[len - 1], dpBought[len - 1]);
    }
};