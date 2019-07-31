//盛水最多的容器
//双指针法

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area =0;
        int lptr = 0;
        int rptr = height.size() - 1;

        while(lptr != rptr)
        {
            max_area = max(max_area, min(height[rptr], height[lptr]) * (rptr - lptr));
            if(height[lptr] >= height[rptr]) rptr--;
            else lptr++;
        }

        return max_area;
    }
};