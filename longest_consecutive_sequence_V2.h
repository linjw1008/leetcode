#include "common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> set;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i)
            set.insert(nums[i]);
        for (int i = 0; i < nums.size(); ++i)
        {
            //nums[i] - 1不在集合中，即以nums[i]为序列的起始
            if (set.find(nums[i] - 1) == set.end())
            {
                int curAns = 1;
                int next = nums[i];
                while (set.find(++next) != set.end())
                    curAns++;
                ans = max(curAns, ans);
            }
        }
        
        
        return ans;
    }
};