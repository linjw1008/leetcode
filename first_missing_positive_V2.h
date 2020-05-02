#include "common.h"

//第一个缺失的正数

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = nums.size() + 1;
        //先把数组排成[1 2 3 4 5]
        for (int i = 0; i < nums.size(); ++i)
        {
            //这里要注意判断nums[i] != nums[nums[i] - 1]，防止无限交换下去
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1] && nums[i] != i + 1)
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        //找到第一个位置与数据不匹配的元素
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                ans = i + 1;
                break;
            }
        }
        
        return ans;
    }
};