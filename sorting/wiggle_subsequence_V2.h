#include "common.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        //动态规划
        //以第i个元素结尾的上升序列的长度
        vector<int> up(nums.size(), 0);
        //以第j个元素结尾的下降序列的长度
        vector<int> down(nums.size(), 0);
        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            //本元素属于上升序列
            if (nums[i] > nums[i - 1])
            {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            //属于下降序列
            else if (nums[i] < nums[i - 1])
            {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else
            {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }

        return max(down[nums.size() - 1], up[nums.size() - 1]);
    }
};