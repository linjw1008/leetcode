#ifndef _SUBSETS_V2_H_
#define _SUBSETS_V2_H_

//子集
//回溯

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> subset;
        vector<int> now_set = {};
        subset.push_back(now_set);
        Subsets(subset, nums, now_set, 0);
        return subset;
    }

    void Subsets(vector<vector<int>>& subset, vector<int>& nums, vector<int>& now_set, int i)
    {
        if (i == nums.size())
            return;
        now_set.push_back(nums[i]);
        subset.push_back(now_set);
        Subsets(subset, nums, now_set, i + 1);
        now_set.pop_back();
        Subsets(subset, nums, now_set, i + 1);
        return;
    }
};

#ifndef