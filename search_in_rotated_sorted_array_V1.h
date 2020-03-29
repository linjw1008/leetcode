//搜索旋转排序数组
//根据与旋转点的位置进行分类判断

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int len = nums.size();
        if (len == 0)
        {
            return ret;
        }

        int lptr = 0;
        int rptr = len - 1;

        while (lptr <= rptr)
        {
            int mptr = (lptr + rptr) / 2;
            //若找到目标，直接返回
            if (nums[mptr] == target)
            {
                ret = mptr;
                break;
            }
            else if (nums[lptr] == target)
            {
                ret = lptr;
                break;
            }
            else if (nums[rptr] == target)
            {
                ret = rptr;
                break;
            }
            //没找到的情况1，当前范围横跨旋转点
            else if (nums[lptr] > nums[rptr])
            {
                //在旋转点右侧
                if (target < nums[lptr])
                {
                    //旋转点在中点右侧
                    if (nums[mptr] > nums[lptr])
                    {
                        lptr = mptr + 1;
                    }
                    //旋转点在中点左侧且目标点在中点右侧
                    else if (nums[mptr] < target)
                    {
                        lptr = mptr + 1;
                    }
                    else
                    {
                        rptr = mptr - 1;                        
                    }
                }
                //在旋转点左侧
                else
                {
                    //旋转点在中点右侧或等于中点
                    if (nums[mptr] >= nums[lptr])
                    {
                        if (nums[mptr] < target)
                        {
                            lptr = mptr + 1;
                        }
                        else
                        {
                            rptr = mptr - 1;
                        }                        
                    }
                    else //在中点左侧
                    {
                        rptr = mptr - 1;
                    }
                }
            }
            //没找到的情况2，不横跨旋转点
            else
            {
                if (nums[mptr] < target)
                {
                    lptr = mptr + 1;
                }
                else
                {
                    rptr = mptr - 1;
                }
            }

        }
        return ret;
    }
};