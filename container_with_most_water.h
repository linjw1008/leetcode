#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针法
        int ans = INT_MIN;
        int left = 0, right = height.size() - 1;
        
        while (left < right)
        {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        
        return ans;
    }
};