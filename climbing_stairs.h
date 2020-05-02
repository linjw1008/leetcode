#include "common.h"

class Solution {
public:

    int climbStairs(int n) {
        if (n <= 1) return 1;
        int dp1 = 1, dp2 = 1;
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            ans = dp1 + dp2;
            dp2 = dp1;
            dp1 = ans;
        }

        return ans;
    }
};