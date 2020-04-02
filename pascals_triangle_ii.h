#include "common.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i)
        {
            ans[i] = 1;
            for (int j = i; j > 1; --j)
            {
                ans[j - 1] = ans[j - 2] + ans[j - 1];
            }
        }
        return ans;
    }
};