#ifndef _POW_H_
#define _POW_H_

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return fastPow(1/x, -(long long)n);
        else
            return fastPow(x, n);
    }

    double fastPow(double x, long long n)
    {
        if (n == 0)
            return 1;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};

#endif