#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int pos = 0;
        int curVal = nums[0];
        int ans = 0;
        
        for (int i = 0; i < nums.size(); )
        {
            //储存当前值
            nums[pos++] = curVal;
            //跳过重复值
            while (i < nums.size() && nums[i] == curVal) i++;
            if (i == nums.size()) break;
            curVal = nums[i];
        }
        
        return pos;
    }
};