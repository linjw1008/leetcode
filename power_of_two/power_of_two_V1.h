#ifndef _POWER_OF_TWO_V1_H_
#define _POWER_OF_TWO_V1_H_

//二的幂

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & n - 1) == 0;
    }
};
#endif