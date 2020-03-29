//零钱兑换

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp;
        dp.resize(amount + 1, INT_MAX);
        dp[0] = 0;
        int len = amount + 1;
        sort(coins.begin(), coins.end(), cmp);

        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        

        return dp[amount] > amount ? -1 : dp[amount];
    }

    bool cmp(int& a, int& b)
    {
        return a > b;
    }
};