#include "common.h"


class Solution {
public:
    //此处要用long
    long mod = 1e9 + 7;

    //快速幂
    int quickPow1(int x, int y)
    {
        long ans = 1;

        while (y != 0)
        {
            if (y % 2 == 1) ans = (ans * x) % mod;
            x = ((long)x * (long)x) % mod;
            y = y / 2;
        }

        return ans % mod;
    }

    int quickPow2(int x, int y)
    {
        if (y == 0) return 1;
        if (y == 1) return x % mod;
        int tmp = quickPow2(x, y / 2) % mod;
        return (y % 2 == 0 ? 1 : x) * (tmp % mod) * (tmp % mod) % mod;
    }


    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        int ans;

        //尽可能分成3
        int y = n / 3;
        if (n % 3 == 1)
            y = y - 1;

        ans = quickPow2(3, y);
        if (n - y * 3 != 0) ans = ((long)ans * (n - y * 3)) % mod;

        return ans;
    }
};