#ifndef _DAILY_TEMPERATURES_V1_H_
#define _DAILY_TEMPERATURES_V1_H_

///每日温度
//暴力法 超时

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> ret(0);
        ret.resize(len);
        int tmp = 0;
        for (int i = 0; i < len; i++)
        {
            tmp = 0;
            for (int j = i + 1; j < len; j++)
            {
                tmp++;
                if (T[i] < T[j])
                {
                    ret[i] = tmp;
                    break;
                }
                    
            }
        }

        return ret;
    }
};

#endif