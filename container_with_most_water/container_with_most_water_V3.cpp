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
            int h = 0;
            if(height[lptr] >= height[rptr])
            {
                h = height[rptr];
                rptr--;
            } 
            else
            {
                h = height[lptr];
                lptr++;
            }
            max_area = max(max_area, h*(rptr - lptr + 1));
            
        }

        return max_area;
    }
};