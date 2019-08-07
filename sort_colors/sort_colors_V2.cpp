//颜色分类
//亦称为荷兰国旗问题
//三指针，一次遍历
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int ptr0 = 0;
        int ptr2 = len - 1;
        int ptrCurr = 0;

        while(ptrCurr <= ptr2)
        {
            if(nums[ptrCurr] == 0)
            {
                swap(nums[ptrCurr], nums[ptr0]);
                ptrCurr++;
                ptr0++;
            }
            else if(nums[ptrCurr] == 2)
            {
                swap(nums[ptrCurr], nums[ptr2]);
                ptr2--;
            }
            else
            {
                ptrCurr++;
            }
            
        }
    }
};