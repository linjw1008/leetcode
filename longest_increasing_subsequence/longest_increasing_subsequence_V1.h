#ifndef _LONGEST_INCREASING_SUBSEQUENCE_V1_H_
#define _LONGEST_INCREASING_SUBSEQUENCE_V1_H_

//最长上升子序列
//递归

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int** memo;
        memo = new int*[nums.size() + 1];
        for (int i = 0; i < nums.size() + 1; i++)
        {
            memo[i] = new int[nums.size()];
            memset(memo[i], -1, sizeof(int) * (nums.size()));
        }
        
        return lengthOfLIS(nums, -1, 0, memo);
    }

    //返回从当前元素curpos开始最可能的长度
    int lengthOfLIS(vector<int>& nums, int prevpos, int curpos, int** memo)
    {
        if (curpos == nums.size())
            return 0;
        if (memo[prevpos + 1][curpos] >= 0)
            return memo[prevpos + 1][curpos];
        
        if (prevpos < 0 || nums[curpos] > nums[prevpos])
            return memo[prevpos + 1][curpos] = max(lengthOfLIS(nums, prevpos, curpos + 1, memo), 1 + lengthOfLIS(nums, curpos, curpos + 1, memo));
        return memo[prevpos + 1][curpos] = lengthOfLIS(nums, prevpos, curpos + 1, memo);
    }
};

#endif