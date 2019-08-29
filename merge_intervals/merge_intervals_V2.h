#ifndef _MERGE_INTERVALS_V2_H_
#define _MERGE_INTERVALS_V2_H_

//合并区间
//使用原数组
//超时

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end(), compare);
        int i = 0;
        while (i < intervals.size() - 1)
        {
            vector<int> cur = intervals[i];
            vector<int> next = intervals[i + 1];
            if (cur[1] >= next[0])
            {
                intervals[i][1] = max(cur[1], next[1]);
                intervals.erase(intervals.begin() + i + 1);
                continue;
            }
            i++;
        }

        return intervals;
    }

    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }    
};

#endif