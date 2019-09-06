#ifndef _COIN_CHANGE_V1_H_
#define _COIN_CHANGE_V1_H_

//零钱兑换
//动态规划
//自下而上

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        int max = amount + 1;
        int len = coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];     
    }
};

#endif