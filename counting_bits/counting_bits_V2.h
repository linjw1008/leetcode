#ifndef _COUNTING_BITS_V2_H_
#define _COUNTING_BITS_V2_H_

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
        if (num == 1)
            return {0, 1};
        
        vector<int> ret = {0, 1};
        int index;
        int tmp = 2;

        for (int i = 2; i <= num; i++)
        {
            if (tmp == i)
            {
                index = 0;
                tmp = tmp * 2;
            }
            ret.push_back(ret[index] + 1);
            index++;
        }

        return ret;
    }
};

#endif