#include "common.h"

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        long mod = 1e9 + 7;
        long ans = 1;

        //尽可能分成3
        while (n > 4)
        {
            n -= 3;
            ans = (ans * 3) % mod;    
        }

        if (n != 0) ans = (ans * n) % mod;
        return ans;
    }
};