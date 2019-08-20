#ifndef _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_V2_H_
#define _KTH_LARGEST_ELEMENT_IN_AN_ARRAY_V2_H_

//数组中的第K个最大元素
//快速选择算法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        int mid = 0;
        int begin = 0;
        int end = len - 1;
                
        do
        {
            //分割数组，中轴左边小于中轴，右边大于中轴
            int i, j;
            i = begin + 1;
            j = end;
            while (1)
            {
                for(; i <= end; i++)
                    if(nums[i] > nums[begin])
                        break;
                for(; j > begin; j--)
                    if(nums[j] < nums[begin])
                        break;
                if(i < j)
                    swap(nums[i], nums[j]);
                else
                    break;        
            }
            swap(nums[begin], nums[j]);
            
            //判断排序左区间还是右区间
            mid = j;
            if(mid < len - k)
                begin = mid + 1;
            else
                end = mid - 1;
            
        }while(mid != len - k);

        return nums[mid];
    }
};

#endif