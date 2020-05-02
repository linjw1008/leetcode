#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[pos++] = nums[i];
            if (pos > 1 && nums[pos - 1] == nums[pos - 2])
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
        }
        
        return pos;
    }
};