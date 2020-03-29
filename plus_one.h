#include "common.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> tmp(len + 1, 0);
        int flag = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            tmp[i + 1] = digits[i] + flag;
            if (tmp[i + 1] >= 10)
            {
                tmp[i + 1] = tmp[i + 1] - 10;
                flag = 1;
            }
            else
                flag = 0;
        }
        
        tmp[0] = flag;
        
        if (tmp[0] != 0) return tmp;
        vector<int> ans(tmp.begin() + 1, tmp.end());
        return ans;
    }
};