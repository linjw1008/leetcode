#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            //跳过重复元素
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
            nums[pos++] = nums[i];
        }
        
        return pos;
    }
};