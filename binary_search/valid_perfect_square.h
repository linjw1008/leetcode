#include "common.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num / 2 + 1;
        
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid == num) return true;
            else if (mid * mid < num) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};