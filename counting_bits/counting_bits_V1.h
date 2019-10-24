#ifndef _COUNTING_BITS_V1_H_
#define _COUNTING_BITS_V1_H_

//比特位计数
//pop count

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    //返回num的汉明距离
    int popCount(int num)
    {
        int count;
        for (count = 0; num != 0; count++)
            num &= num - 1;

        return count;
    }
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0; i <= num; i++)
            ret.push_back(popCount(i));

        return ret;
    }
};

#endif