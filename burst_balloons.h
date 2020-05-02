#include "common.h"

class Solution {
public:
    int dp(vector<int>& nums, int left, int right, vector<vector<int>>& mem)
    {
        if (mem[left][right] > 0)
            return mem[left][right];
        
        if (left + 1 == right)
            return 0;
        
        int ans = 0;
        for (int i = left + 1; i < right; ++i)
            ans = max(ans, nums[i] * nums[left] * nums[right] + dp(nums, left, i, mem) + dp(nums, i, right, mem));
        
        mem[left][right] = ans;
        
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> newNums;
        newNums.push_back(1);
        newNums.insert(newNums.end(), nums.begin(), nums.end());
        newNums.push_back(1);
        vector<vector<int>> mem(newNums.size(), vector<int>(newNums.size(), 0));
        
        return dp(newNums, 0, newNums.size() - 1, mem);
    }
};