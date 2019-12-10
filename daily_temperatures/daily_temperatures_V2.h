#ifndef _DAILY_TEMPERATURES_V2_H_
#define _DAILY_TEMPERATURES_V2_H_

///每日温度
//栈
//用栈维护一个递增列表

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> ret;
        ret.resize(len);
        stack<int> increasingList;

        for (int i = len - 1; i >= 0; i--)
        {
            while (!increasingList.empty() && T[increasingList.top()] <= T[i])
            {
                increasingList.pop();
            }
            if (!increasingList.empty())
            {
                ret[i] = increasingList.top() - i;
            }
            else
            {
                ret[i] = 0;
            }
            increasingList.push(i);
        }

        return ret;
    }
};

#endif