//买卖股票
//暴力法
//超时

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int interest = 0;

        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                interest = max(interest, prices[j] - prices[i]);
            }
        }

        return interest;
    }
};