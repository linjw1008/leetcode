#ifndef _SUBSETS_V1_H_
#define _SUBSETS_V1_H_

//子集
//递归

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<int>> subset;
    unordered_set<string> hash_set;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        Subsets(nums);
        return subset;
    }

    void Subsets(vector<int>& nums)
    {
        string numsString = subset_to_string(nums);
        if (hash_set.count(numsString) > 0)
            return;
        subset.push_back(nums);
        hash_set.insert(numsString);
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            Subsets(tmp);
        }
    }

    string subset_to_string(vector<int>& nums)
    {
        string ret;
        ret = "#";
        for (int i = 0; i < nums.size(); i++)
        {
            ret = ret + to_string(nums[i]);
            ret = ret + "#";
        }
        return ret;
    }
};

#ifndef