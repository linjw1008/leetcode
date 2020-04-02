#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //思路，把所有非零值移到前面，然后把后面的元素全部置零
        int pos = 0;
        for (int i = 0; i < nums.size();)
        {
            //跳过0
            while (i < nums.size() && nums[i] == 0) ++i;
            if (i == nums.size()) break;
            nums[pos++] = nums[i];
            ++i;
        }
        //后面的元素置0
        for (int i = pos; i < nums.size(); ++i)
            nums[i] = 0;
    }
};