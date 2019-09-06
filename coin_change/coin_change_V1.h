#ifndef _COIN_CHANGE_V1_H_
#define _COIN_CHANGE_V1_H_

//零钱兑换
//递归
//超时

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int ret = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (amount - coins[i] < 0) continue;
            int subProb = coinChange(coins, amount - coins[i]);
            if (subProb == -1) continue;
            ret = min(ret, subProb + 1);
        }
        return ret == INT_MAX ? -1 : ret;
    }
};

#endif