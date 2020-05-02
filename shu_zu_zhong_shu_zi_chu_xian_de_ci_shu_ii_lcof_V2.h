#include "common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        //统计每一位，看是否能被3整除
        for (int i = 0; i < 32; ++i)
        {
            int flag = 1 << i;
            int count = 0;
            for (int j = 0; j < nums.size(); ++j)
                if ((nums[j] & flag) == flag) count++;
            ans = ans + ((count % 3) << i);
        }

        return ans;
    }
};