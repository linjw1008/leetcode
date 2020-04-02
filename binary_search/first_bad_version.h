#include "common.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid; //答案肯定在right或者right左边
            else left = mid + 1;
        }
        //跳出循环时，left == right，而由于答案肯定在right或者right左边，所以right即为答案
        
        return left;
    }
};