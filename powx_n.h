#include "common.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool flag = (n < 0);
        n = abs(n);

        while (n > 0)
        {
            if (n & 1) ans *= x;
            x = x * x;
            n = n / 2;
        }
        if (flag) ans = 1.0 / ans;

        return ans;
    }
};