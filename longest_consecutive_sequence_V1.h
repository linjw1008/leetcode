#include "common.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        //先排序，然后用双指针
        sort(nums.begin(), nums.end());
        int ans = 1;
        int pos = 0;
        
        while (pos < nums.size() - 1)
        {
            int curAns = 1;
            //找出当前的递增子序列
            while (pos < nums.size() - 1 && (nums[pos] == nums[pos + 1] || nums[pos + 1] - nums[pos] == 1))
            {
                if (nums[pos] != nums[pos + 1])
                    curAns++;
                pos++;
            }
            ++pos;
            ans = max(curAns, ans);
        }
        
        return ans;
    }
};