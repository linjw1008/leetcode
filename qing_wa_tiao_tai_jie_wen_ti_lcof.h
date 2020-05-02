#include "common.h"

class Solution {
public:
    int mod = 1e9 + 7;
    int numWays(int n) {
        if (n <= 1) return 1;
        int dp1 = 1, dp2 = 1;
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            ans = (dp1%mod + dp2%mod)%mod;
            dp2 = dp1;
            dp1 = ans;
        }

        return ans;
    }
};