#include "common.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> set;
        int maxVal = -1, minVal = 14;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                if (set.find(nums[i]) != set.end()) return false;
                set.insert(nums[i]);
                maxVal = max(nums[i], maxVal);
                minVal = min(nums[i], minVal);
            }
        }
        return maxVal - minVal < 5;
    }
};