#include "common.h"

class Solution {
public:
    int quickPow(int a, int b)
    {
        int ans = 1;

        while (b > 0)
        {
            if (b % 2 == 1) ans = ans * a;
            a = a * a;
            b = b / 2;
        }

        return ans;
    }

    vector<int> printNumbers(int n) {
        int maxNum = quickPow(10, n);
        vector<int> ans;
        
        for (int i = 1; i < maxNum; ++i)
            ans.push_back(i);
        
        return ans;
    }
};