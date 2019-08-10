//买卖股票
//一次遍历

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int interest = 0;
        int min_price = INT_MAX;

        for(int i = 0; i < len; i++)
        {
            min_price = min(min_price, prices[i]);
            interest = max(prices[i] - min_price, interest);
        }

        return interest;
    }
};