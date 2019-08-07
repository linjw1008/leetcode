//颜色分类
//亦称为荷兰国旗问题
//两次遍历法
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int r = 0, g = 0, b = 0;
        for(int i = 0; i < len; i++)
        {
            switch (nums[i])
            {
            case 0:
                r++;
                break;
            case 1:
                g++;
                break;
            case 2:
                b++;
                break;
            default:
                break;
            }
        }
        for(int i = 0; i < r; i++) nums[i] = 0;
        for(int i = r; i < r+g; i++) nums[i] = 1;
        for(int i = r+g; i < len; i++) nums[i] = 2;
    }
};