#ifndef _PERMUTATIONS_V1_H_
#define _PERMUTATIONS_V1_H_

//全排列
//回溯法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        backtrack(len, nums, res, 0);
        return res;
    }

    void backtrack(int n, vector<int>& nums, vector<vector<int>>& res, int first)
    {
        if (first == n)
            res.push_back(nums);
        for (int i = first; i < n; i++)
        {
            swap(nums[i], nums[first]);
            backtrack(n, nums, res, first + 1);
            swap(nums[i], nums[first]);
        }
    }
};

#endif