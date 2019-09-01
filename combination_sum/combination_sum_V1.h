#ifndef _COMBINATION_SUM_V1_H_
#define _COMBINATION_SUM_V1_H_

//组合总数
//回溯法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> combination;
    vector<int> path;
    vector<int> candidates;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return combination;

        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        combinationSum(0, target);

        return combination;
    }

    void combinationSum(int start, int target) {
        if (target == 0)
        {
            combination.push_back(path);
            return;
        }
        
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            path.push_back(candidates[i]);
            combinationSum(i, target - candidates[i]);
            path.pop_back();
        }

        return;
    }
};

#endif