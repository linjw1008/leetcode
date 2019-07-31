//盛水最多的容器
//暴力法
//超出时间限制

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        short len = height.size();

        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                max_area = max(max_area, min(height[i], height[j])*(j - i));
            }
        }
        return max_area;
    }
};