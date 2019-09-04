#ifndef _SUBSETS_V4_H_
#define _SUBSETS_V4_H_

//子集
//分治法
//递归实现

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        if (nums.size() == 0)
            return {{}};
        int tmp = nums.back();
        nums.pop_back();
        vector<vector<int>> tmp_vec = subsets(nums);
        int len = tmp_vec.size();
        for (int i = 0; i < len; i++)
        {
            tmp_vec.push_back(tmp_vec[i]);
            tmp_vec[i].push_back(tmp);
        }
        return tmp_vec;
    }
};

#ifndef