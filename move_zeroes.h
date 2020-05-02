#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //思路，把所有非零值移到前面，然后把后面的元素全部置零
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                nums[pos++] = nums[i];
        while (pos < nums.size()) nums[pos++] = 0;
    }
};