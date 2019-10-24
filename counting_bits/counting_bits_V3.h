#ifndef _COUNTING_BITS_V3_H_
#define _COUNTING_BITS_V3_H_

//比特位计数
//动态规划

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        
        vector<int> ret = {0};

        //转移函数
        //P(x) = P(x/2) + (x mod 2)
        for (int i = 1; i <= num; i++)
            ret.push_back(ret[i>>1] + (i&1));

        return ret;
    }
};

#endif