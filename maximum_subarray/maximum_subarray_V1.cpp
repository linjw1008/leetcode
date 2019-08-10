//最大子序和
//一次遍历、动态规划V1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int max_sum = nums[0];
        int sum = nums[0];

        for(int i = 1; i < len; i++)
        {
            sum = sum > 0 ? sum + nums[i] : nums[i];
            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }
};