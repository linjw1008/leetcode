#include "common.h"

//分治法

class Solution {
public:
    int helper(vector<int>& heights, int left, int right)
    {
        if (left > right)
            return 0;
        
        int lowest = left;
        for (int i = left; i <= right; ++i)
            if (heights[i] <= heights[lowest])
                lowest = i;
        
        return max(heights[lowest] * (right - left + 1), max(helper(heights, left, lowest - 1), helper(heights, lowest + 1, right)));
    }
    
    int largestRectangleArea(vector<int>& heights) {
        //分治法
        return helper(heights, 0, heights.size() - 1);
    }
};