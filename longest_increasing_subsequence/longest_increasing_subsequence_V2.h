#ifndef _LONGEST_INCREASING_SUBSEQUENCE_V2_H_
#define _LONGEST_INCREASING_SUBSEQUENCE_V2_H_

//最长上升子序列
//动态规划

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int* dp = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            dp[i] = 1;
        
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};

#endif