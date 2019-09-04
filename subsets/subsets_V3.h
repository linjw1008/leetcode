#ifndef _SUBSETS_V3_H_
#define _SUBSETS_V3_H_

//子集
//动态规划

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> subset;
        subset.push_back({});
        for (int i = 0; i < nums.size(); i++)
        {
            int len = subset.size();
            for (int j = 0; j < len; j++)
            {
                vector<int> tmp = subset[j];
                tmp.push_back(nums[i]);
                subset.push_back(tmp);
            }
            
        }
        return subset;
    }
};

#ifndef