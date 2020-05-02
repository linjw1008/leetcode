#include "common.h"

//第一个缺失的正数

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<long> set;
        for (int i = 0; i < nums.size(); ++i)
            set.insert(nums[i]);
        
        long ans = LONG_MAX;
        if (set.find(1) == set.end())
            ans = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= 0 && set.find((long)nums[i] + 1) == set.end())
                ans = min((long)nums[i] + 1, ans);
        }
        
        return ans;
    }
};