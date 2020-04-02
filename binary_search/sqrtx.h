#include "common.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        //二分查找0 ~ x/2
        int left = 0;
        int right = x / 2;
        long mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if ((mid * mid) <= x && ((mid + 1) * (mid + 1)) > x) return mid;
            else if (mid * mid > x) right = mid - 1;
            else left = mid + 1;
        }
        
        return mid;
    }
};