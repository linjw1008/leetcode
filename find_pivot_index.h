//寻找数组的中心索引
#include "common.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        int leftSum = 0;
        for (int i = 0; i < nums.size();++i)
            rightSum += nums[i];
        
        for (int i = 0; i < nums.size(); ++i)
        {
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        
        return -1;
    }
};