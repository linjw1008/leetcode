#ifndef _MERGE_INTERVALS_V1_H_
#define _MERGE_INTERVALS_V1_H_

//合并区间

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        int count = 0;
        vector<vector<int>> ret;
        if(len <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), compare);
        ret.push_back(intervals[0]);
        for (int i = 1; i < len; i++)
        {
            if (ret[count][1] < intervals[i][0])
            {
                count++;
                ret.push_back(intervals[i]);
            }
            else
                ret[count][1] = max(ret[count][1], intervals[i][1]);
        }

        return ret;
    }

    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }    
};

#endif